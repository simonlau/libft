#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>
#if defined(__GLIBC__)
# include <bsd/string.h>
#endif

tstsuite("ft_strlcpy") {
    tstcase("property test matches strlcpy oracle", i) {
        char *str;
        size_t num;
        char *actual;
        char *expected;
        size_t result;
        
        srand(SEED);
        int i;
        for (i = 0; i < 2000; i++) {
            int slen = rand() % 64;
            str = malloc(slen + 1);
            if (str == NULL) continue;
            for (int j = 0; j < slen; j++)
                str[j] = (char)(rand() % 95 + 32);
            str[slen] = '\0';
            num = rand() % 64;
            actual = calloc(num + 1, sizeof(*actual));
            if (actual == NULL) continue;
            result = ft_strlcpy(actual, str, num);
            expected = calloc(num + 1, sizeof(*expected));
            if (expected == NULL) { free(actual); free(str); continue; }
            snprintf(expected, num + 1, "%s", str);
            tstexpect(result == strlen(expected) && memcmp(actual, expected, num) == 0,
                     "ft_strlcpy mismatch for len=%zu", num);
            free(actual);
            free(expected);
            free(str);
        }
    }
}