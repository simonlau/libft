#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

tstsuite("ft_putendl_fd") {
    tstcase("property writes string plus newline to the fd") {
        char	*s;
        int		fds[2];
        char	stack[4096];
        char	*out;
        size_t	len;
        size_t	cap;
        ssize_t	total;
        size_t	more;
        int		i;
        int		ok;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s = make_rand_str();
            if (s == NULL)
                continue ;
            len = strlen(s);
            cap = len + 1;
            out = (cap > sizeof(stack)) ? malloc(cap) : stack;
            if (out == NULL)
            {
                free(s);
                continue ;
            }
            if (pipe(fds) != 0)
            {
                if (out != stack)
                    free(out);
                free(s);
                continue ;
            }
            ft_putendl_fd(s, fds[PIPE_WRITE_END]);
            close(fds[PIPE_WRITE_END]);
            total = capture_begin(fds[PIPE_READ_END], out, cap);
            more = 0;
            if (total < 0)
                ok = 0;
            else
            {
                more = capture_end(fds[PIPE_READ_END]);
                ok = ((size_t)total == cap && more == 0
                     && (len == 0 || memcmp(out, s, len) == 0)
                     && out[len] == '\n');
            }
            if (out != stack)
                free(out);
            free(s);
            tstexpect(ok,
                "ft_putendl_fd(%s) wrote %zd bytes, extra %zu, newline %d",
                s, total, more, out[len] == '\n');
        }
    }
}
