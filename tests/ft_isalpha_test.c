#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_isalpha") {
    tstcase("property test matches isalpha oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(0);
        for (i = 0; i < 2000; i++) {
            c = (unsigned char)rand();
            result = ft_isalpha(c);
            expected = isalpha(c);
            if ((expected == 0 && result == 0) || (expected != 0 && result == 1))
                tstcheck(1, "ft_isalpha(%d) = %d = %d", c, result, expected);
            else
                tstcheck(0, "ft_isalpha(%d) = %d != %d", c, result, expected);
        }
    }
}