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
        size_t	total;
        size_t	extra;
        ssize_t	r;
        int		i;
        int		ok;
        int		read_err;

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
            ft_putnbr_fd(num, fds[1]);
            close(fds[1]);
            total = 0;
            read_err = 0;
            while (total < len)
            {
                r = read(fds[0], out + total, len - total);
                if (r == 0)
                    break ;
                if (r < 0)
                {
                    read_err = 1;
                    break ;
                }
                total += (size_t)r;
            }
            if (!read_err)
            {
                extra = 0;
                while (1)
                {
                    r = read(fds[0], stack, sizeof(stack));
                    if (r == 0)
                        break ;
                    if (r < 0)
                    {
                        read_err = 1;
                        break ;
                    }
                    extra += (size_t)r;
                }
            }
            close(fds[0]);
            ok = 1;
            if (read_err)
                ok = 0;
            else if (total != len || extra != 0
                     || (len > 0 && memcmp(out, expected, len) != 0))
                ok = 0;
            if (out != stack)
                free(out);
            tstexpect(ok,
                "ft_putnbr_fd(%d) wrote %zu bytes, extra %zu", num, total, extra);
        }
    }
}
