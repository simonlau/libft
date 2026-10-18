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
        for (i = 0; i < 2000; i++) {
            num = rand() % INT_MAX - (rand() % 2);
            result = ft_itoa(num);
            if (result == NULL) continue;
            expected = atoi(result);
            tstexpect(expected == num, "ft_itoa(%d) roundtrip fail: got %d", num, expected);
            free(result);
        }
    }
}