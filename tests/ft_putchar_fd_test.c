#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

tstsuite("ft_putchar_fd") {
    tstcase("property writes exactly one byte to the fd") {
        char	c;
        int		fds[2];
        char	out;
        char	extra[16];
        size_t	total;
        ssize_t	r;
        size_t	more;
        int		i;
        int		ok;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            c = (char)rand();
            if (pipe(fds) != 0)
                continue ;
            ft_putchar_fd(c, fds[PIPE_WRITE_END]);
            close(fds[PIPE_WRITE_END]);
            total = 0;
            while (total < 1)
            {
                r = read(fds[PIPE_READ_END], &out + total, 1 - total);
                if (r == 0)
                    break ;
                if (r < 0)
                {
                    close(fds[PIPE_READ_END]);
                    continue ;
                }
                total += (size_t)r;
            }
            more = 0;
            while (1)
            {
                r = read(fds[PIPE_READ_END], extra, sizeof(extra));
                if (r == 0)
                    break ;
                if (r < 0)
                {
                    close(fds[PIPE_READ_END]);
                    continue ;
                }
                more += (size_t)r;
            }
            close(fds[PIPE_READ_END]);
            ok = (total == 1 && more == 0 && memcmp(&out, &c, 1) == 0);
            tstexpect(ok,
                "ft_putchar_fd(%d) wrote %zu bytes, extra %zu", c, total, more);
        }
    }
}
