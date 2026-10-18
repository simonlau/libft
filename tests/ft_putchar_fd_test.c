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
		ssize_t	total;
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
            total = capture_begin(fds[PIPE_READ_END], &out, 1);
            if (total < 0)
            {
                close(fds[PIPE_READ_END]);
                continue ;
            }
            more = capture_end(fds[PIPE_READ_END]);
            ok = (total == 1 && more == 0 && memcmp(&out, &c, 1) == 0);
            tstexpect(ok,
                "ft_putchar_fd(%d) wrote %zd bytes, extra %zu", c, total, more);
        }
    }
}
