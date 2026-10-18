#include "libft.h"
#include "tst.h"
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

tstsuite("ft_calloc") {
    tstcase("property matches libc calloc (zeroed allocation)") {
        size_t	count;
        size_t	size;
        void	*actual;
        void	*expected;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            count = (size_t)rand();
            size = (size_t)rand();
            if (count == 0 || size == 0
                || (size != 0 && count > SIZE_MAX / size))
            {
                void	*p = ft_calloc(count, size);

                free(p);
                continue ;
            }
            {
                size_t	len = count * size; /* safe: non-overflow branch */

                if (len > (1ULL << 20)) /* skip huge allocs that abort under ASan */
                    continue ;
            }
            actual = ft_calloc(count, size);
            expected = calloc(count, size);
            if (actual == NULL && expected == NULL) {
                /* both failed to allocate: consistent */
                continue ;
            }
            if (actual == NULL || expected == NULL) {
                tstexpect(0,
                    "ft_calloc(%zu, %zu) NULL mismatch with calloc", count, size);
                free(actual);
                free(expected);
                continue ;
            }
            tstexpect(memcmp(actual, expected, count) == 0,
                "ft_calloc(%zu, %zu) is not zeroed like calloc", count, size);
            free(actual);
            free(expected);
        }
    }
}
