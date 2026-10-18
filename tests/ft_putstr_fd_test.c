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
        size_t	total;
        ssize_t	r;
        size_t	extra;
        int		i;
        int		ok;
        int		read_err;

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
            ft_putstr_fd(s, fds[1]);
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
                     || (len > 0 && memcmp(out, s, len) != 0))
                ok = 0;
            if (out != stack)
                free(out);
            free(s);
            tstexpect(ok,
                "ft_putstr_fd(%s) wrote %zu bytes, extra %zu", s, total, extra);
        }
    }
}
