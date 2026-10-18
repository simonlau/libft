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
}