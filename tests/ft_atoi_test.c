#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

tstsuite("ft_atoi") {
    tstcase("property test matches atoi oracle") {
        unsigned int n;
        char buf[256];
        const char *sign;
        int result;
        int expected;

        srand(SEED);
        int i;
        for (i = 0; i < TRIALS; i++) {
            int val = rand() % INT_MAX - (rand() % 2);
            n = (unsigned int)val;
            sign = n % 3 == 0 ? "+" : (n % 3 == 1 ? "-" : "");
            snprintf(buf, sizeof(buf), "%*s%s%d", n % 20, "", sign, val);
            result = ft_atoi(buf);
            expected = atoi(buf);
            tstexpect(result == expected, "ft_atoi(%d) = %d != %d", val, result, expected);
        }
    }

    tstcase("edge overflow and INT_MIN boundaries") {
        const char *cases[] = {
            "2147483647",   /* INT_MAX (boundary, well-defined) */
            "-2147483648",  /* INT_MIN (boundary, well-defined) */
            "+2147483647",
            "-2147483648",
            "  2147483647",
            "\t-2147483648",
            "",             /* empty -> 0 */
            "   ",          /* whitespace only -> 0 */
            "+-12",         /* invalid sign sequence -> 0 */
            "--12",         /* invalid sign sequence -> 0 */
            "12abc",        /* stops at first non-digit -> 12 */
        };
        size_t n = sizeof(cases) / sizeof(cases[0]);
        int result;
        int expected;
        for (size_t i = 0; i < n; i++) {
            result = ft_atoi(cases[i]);
            expected = atoi(cases[i]);
            tstexpect(result == expected,
                "ft_atoi(\"%s\") = %d != %d", cases[i], result, expected);
        }
    }
}
