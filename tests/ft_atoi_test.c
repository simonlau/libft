#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

tstsuite("ft_atoi") {
    tstcase("property test matches atoi oracle", i) {
        int num;
        unsigned int n;
        char buf[256];
        char sign;
        int result;
        int expected;

        srand(0);
        for (i = 0; i < 2000; i++) {
            int val = rand() % INT_MAX - (rand() % 2);
            n = (unsigned int)val;
            sign = n % 3 == 0 ? '+' : (n % 3 == 1 ? '-' : '');
            snprintf(buf, sizeof(buf), "%*s%s%d", n % 20, "", sign, val);
            result = ft_atoi(buf);
            expected = atoi(buf);
            if (result == expected)
                tstcheck(true, "ft_atoi(%d) = %d = %d", val, result, expected);
            else
                tstcheck(false, "ft_atoi(%d) = %d != %d", val, result, expected);
        }
    }
}