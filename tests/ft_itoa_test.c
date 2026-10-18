#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

tstsuite("ft_itoa") {
    tstcase("roundtrip from ft_itoa to atoi") {
        int num;
        char *result;
        int expected;
        
        srand(SEED);
        int i;
        for (i = 0; i < TRIALS; i++) {
            num = rand() % INT_MAX - (rand() % 2);
            result = ft_itoa(num);
            if (result == NULL) continue;
            expected = atoi(result);
            tstexpect(expected == num, "ft_itoa(%d) roundtrip fail: got %d", num, expected);
            free(result);
        }
    }

    tstcase("edge extreme values") {
        const char *cases[] = {
            "0",      /* 0 */
            "1",      /* 1 */
            "-1",     /* -1 */
            "2147483647",   /* INT_MAX */
            "-2147483648",  /* INT_MIN */
        };
        int         vals[] = { 0, 1, -1, INT_MAX, INT_MIN };
        size_t      n = sizeof(cases) / sizeof(cases[0]);
        char       *result;
        int         i;

        for (i = 0; i < (int)n; i++) {
            result = ft_itoa(vals[i]);
            tstexpect(result != NULL && strcmp(result, cases[i]) == 0,
                "ft_itoa(%d) = %s != %s", vals[i], result ? result : "(null)", cases[i]);
            free(result);
        }
    }
}