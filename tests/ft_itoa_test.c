#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_itoa") {
    tstcase("roundtrip from ft_itoa to atoi", i) {
        int num;
        char *result;
        int expected;
        
        srand(0);
        for (i = 0; i < 2000; i++) {
            num = rand() % INT_MAX - (rand() % 2);
            result = ft_itoa(num);
            if (result == NULL) continue;
            expected = atoi(result);
            if (expected == num)
                tstcheck(true, "ft_itoa(%d) roundtrip OK", num);
            else
                tstcheck(false, "ft_itoa(%d) roundtrip fail: got %d", num, expected);
            free(result);
        }
    }
}