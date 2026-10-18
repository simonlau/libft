#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_memcpy") {
    tstcase("property test matches memcpy oracle", i) {
        char *str;
        int len;
        char *expected;
        char *actual;
        char *result;
        
        srand(0);
        for (i = 0; i < 2000; i++) {
            len = rand() % 64;
            str = malloc(len + 1);
            if (str == NULL) continue;
            for (int j = 0; j < len; j++)
                str[j] = (char)(rand() % 95 + 32);
            str[len] = '\0';
            actual = malloc(len * sizeof(*actual));
            expected = malloc(len * sizeof(*expected));
            if (actual == NULL || expected == NULL) { free(str); free(actual); free(expected); continue; }
            memcpy(expected, str, len);
            result = ft_memcpy(actual, str, len);
            if (memcmp(actual, expected, len) == 0 && result == actual)
                tstcheck(true, "ft_memcpy OK for len=%d", len);
            else
                tstcheck(false, "ft_memcpy mismatch for len=%d", len);
            free(str);
            free(actual);
            free(expected);
        }
    }
}