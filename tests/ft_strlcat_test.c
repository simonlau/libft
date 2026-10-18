#include "libft.h"
#include "tst.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>
#if defined(__GLIBC__)
# include <bsd/string.h>
#endif

tstsuite("ft_strlcat") {
    tstcase("property test matches strlcat oracle") {
        char *dst;
        char *src;
        uint16_t num;
        char *actual;
        char *expected;
        size_t result;
        size_t expected_result;
        
        srand(SEED);
        int i;
        for (i = 0; i < 2000; i++) {
            int dlen = rand() % 64;
            int slen = rand() % 64;
            dst = malloc(dlen + 1);
            src = malloc(slen + 1);
            if (dst == NULL || src == NULL) { free(dst); free(src); continue; }
            for (int j = 0; j < dlen; j++)
                dst[j] = (char)(rand() % 95 + 32);
            dst[dlen] = '\0';
            for (int j = 0; j < slen; j++)
                src[j] = (char)(rand() % 95 + 32);
            src[slen] = '\0';
            num = rand() % 32 + 1;
            actual = calloc(num, sizeof(*actual));
            if (actual == NULL) continue;
            snprintf(actual, num, "%s", dst);
            expected = calloc(num, sizeof(*expected));
            if (expected == NULL) { free(actual); free(dst); free(src); continue; }
            snprintf(expected, num, "%s", dst);
            result = ft_strlcat(actual, src, num);
            expected_result = strlcat(expected, src, num);
            tstexpect(result == expected_result && memcmp(actual, expected, num) == 0,
                     "ft_strlcat mismatch for num=%u", num);
            free(actual);
            free(expected);
            free(dst);
            free(src);
        }
    }
}