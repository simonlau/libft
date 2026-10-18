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
        size_t	total;
        ssize_t	r;
        size_t	off;
        int		i;
        int		ok;
        int		read_err;

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
            ft_putendl_fd(s, fds[1]);
            close(fds[1]);
            total = 0;
            read_err = 0;
            while (total < cap)
            {
                r = read(fds[0], out + total, cap - total);
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
                off = 0;
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
                    off += (size_t)r;
                }
            }
            close(fds[0]);
            ok = 1;
            if (read_err)
                ok = 0;
            else if (total != cap || off != 0
                     || (len > 0 && memcmp(out, s, len) != 0)
                     || out[len] != '\n')
                ok = 0;
            if (out != stack)
                free(out);
            free(s);
            tstexpect(ok,
                "ft_putendl_fd(%s) wrote %zu bytes, extra %zu, newline %d",
                s, total, off, out[len] == '\n');
        }
    }
}
