#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_strrchr") {
    tstcase("property test matches strrchr oracle", i) {
        char *s;
        int c;
        char *expected;
        char *result;
        
        srand(0);
        for (i = 0; i < 2000; i++) {
            int slen = rand() % 64;
            s = malloc(slen + 1);
            if (s == NULL) continue;
            for (int j = 0; j < slen; j++)
                s[j] = (char)(rand() % 95 + 32);
            s[slen] = '\0';
            c = rand() % 256;
            result = ft_strrchr(s, c);
            expected = strrchr(s, c);
            if (result == expected)
                tstcheck(true, "ft_strrchr OK for c=%d", c);
            else
                tstcheck(false, "ft_strrchr mismatch for c=%d", c);
            free(s);
        }
    }
}