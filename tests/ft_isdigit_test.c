#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_isdigit") {
    tstcase("property test matches isdigit oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(0);
        for (i = 0; i < 2000; i++) {
            c = (unsigned char)rand();
            result = ft_isdigit(c);
            expected = isdigit(c);
            if ((expected == 0 && result == 0) || (expected != 0 && result == 1))
                tstcheck(1, "ft_isdigit(%d) = %d = %d", c, result, expected);
            else
                tstcheck(0, "ft_isdigit(%d) = %d != %d", c, result, expected);
        }
    }
}