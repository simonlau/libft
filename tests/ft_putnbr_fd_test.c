#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

tstsuite("ft_putnbr_fd") {
    tstcase("property writes the integer text to the fd") {
        int		num;
        int		fds[2];
        char	expected[32];
        size_t	len;
        char	stack[4096];
        char	*out;
        ssize_t	total;
        int		i;
        int		ok;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            num = (int)rand();
            snprintf(expected, sizeof(expected), "%d", num);
            len = strlen(expected);
            out = (len > sizeof(stack)) ? malloc(len) : stack;
            if (len != 0 && out == NULL)
            {
                continue ;
            }
            if (pipe(fds) != 0)
            {
                if (out != stack)
                    free(out);
                continue ;
            }
            ft_putnbr_fd(num, fds[PIPE_WRITE_END]);
            close(fds[PIPE_WRITE_END]);
            total = capture_begin(fds[PIPE_READ_END], out, len);
            if (total < 0)
                ok = 0;
            else
            {
                size_t	more = capture_end(fds[PIPE_READ_END]);
                ok = ((size_t)total == len && more == 0
                     && (len == 0 || memcmp(out, expected, len) == 0));
            }
            if (out != stack)
                free(out);
            tstexpect(ok,
                "ft_putnbr_fd(%d) wrote %zd bytes", num, total);
        }
    }
}
