#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_isalnum") {
    tstcase("property test matches isalnum oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(0);
        for (i = 0; i < 2000; i++) {
            c = (unsigned char)rand();
            result = ft_isalnum(c);
            expected = isalnum(c);
            if ((expected == 0 && result == 0) || (expected != 0 && result == 1))
                tstcheck(1, "ft_isalnum(%d) = %d = %d", c, result, expected);
            else
                tstcheck(0, "ft_isalnum(%d) = %d != %d", c, result, expected);
        }
    }
}