#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <ctype.h>

tstsuite("ft_tolower") {
    tstcase("property test matches tolower oracle") {
        int i;
        unsigned char c;
        int result;
        int expected;

        srand(0);
        for (i = 0; i < 2000; i++) {
            c = (unsigned char)rand();
            result = ft_tolower(c);
            expected = tolower(c);
            if (result == expected)
                tstcheck(1, "ft_tolower(%d) = %d = %d", c, result, expected);
            else
                tstcheck(0, "ft_tolower(%d) = %d != %d", c, result, expected);
        }
    }
}