#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_strrchr") {
    tstcase("property test matches strrchr oracle") {
        char *s;
        int c;
        char *expected;
        char *result;
        
        srand(SEED);
        int i;
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
            tstexpect(result == expected, "ft_strrchr mismatch for c=%d", c);
            free(s);
        }
    }
}