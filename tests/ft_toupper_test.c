#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_toupper") {
    tstcase("property test matches toupper oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(0);
        for (i = 0; i < 2000; i++) {
            c = (unsigned char)rand();
            result = ft_toupper(c);
            expected = toupper(c);
            if (result == expected)
                tstcheck(1, "ft_toupper(%d) = %d = %d", c, result, expected);
            else
                tstcheck(0, "ft_toupper(%d) = %d != %d", c, result, expected);
        }
    }
}