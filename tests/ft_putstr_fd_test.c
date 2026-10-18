#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

tstsuite("ft_putstr_fd") {
    tstcase("property writes the full string to the fd") {
        char	*s;
        int		fds[2];
        char	stack[4096];
        char	*out;
        size_t	len;
        ssize_t	total;
        int		i;
        int		ok;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s = make_rand_str();
            if (s == NULL)
                continue ;
            len = strlen(s);
            out = (len > sizeof(stack)) ? malloc(len) : stack;
            if (len != 0 && out == NULL)
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
            ft_putstr_fd(s, fds[PIPE_WRITE_END]);
            close(fds[PIPE_WRITE_END]);
            total = capture_begin(fds[PIPE_READ_END], out, len);
            if (total < 0)
                ok = 0;
            else
            {
                size_t	more = capture_end(fds[PIPE_READ_END]);
                ok = ((size_t)total == len && more == 0
                     && (len == 0 || memcmp(out, s, len) == 0));
            }
            if (out != stack)
                free(out);
            free(s);
            tstexpect(ok,
                "ft_putstr_fd(%s) wrote %zd bytes", s, total);
        }
    }
}
