#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_isprint") {
    tstcase("property test matches isprint oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(0);
        for (i = 0; i < 2000; i++) {
            c = (unsigned char)rand();
            result = ft_isprint(c);
            expected = isprint(c);
            if ((expected == 0 && result == 0) || (expected != 0 && result == 1))
                tstcheck(1, "ft_isprint(%d) = %d = %d", c, result, expected);
            else
                tstcheck(0, "ft_isprint(%d) = %d != %d", c, result, expected);
        }
    }
}