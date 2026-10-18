#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_bzero") {
    tstcase("property test matches calloc oracle", i) {
        char *s;
        int len;
        char *expected;
        char *actual;
        
        srand(0);
        for (i = 0; i < 2000; i++) {
            len = rand() % 64;
            s = malloc(len + 1);
            if (s == NULL) continue;
            for (int j = 0; j < len; j++)
                s[j] = (char)(rand() % 95 + 32);
            s[len] = '\0';
            actual = strdup(s);
            expected = calloc(len, len * sizeof(*expected));
            if (expected == NULL) { free(s); free(actual); continue; }
            ft_bzero(actual, len);
            if (memcmp(actual, expected, len) == 0)
                tstcheck(true, "ft_bzero OK for len=%d", len);
            else
                tstcheck(false, "ft_bzero mismatch for len=%d", len);
            free(s);
            free(actual);
            free(expected);
        }
    }
}