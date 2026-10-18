#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#if defined(__GLIBC__)
# include <bsd/string.h>
#endif

tstsuite("ft_strlcat") {
    tstcase("property test matches strlcat oracle", i) {
        char *dst;
        char *src;
        uint16_t num;
        char *actual;
        char *expected;
        size_t result;
        int dst_len;
        
        srand(0);
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
            dst_len = dst[0] ? dlen : 0;
            snprintf(actual, num, "%s", dst);
            expected = calloc(num, sizeof(*expected));
            if (expected == NULL) { free(actual); free(dst); free(src); continue; }
            snprintf(expected, num, "%s", dst);
            result = ft_strlcat(actual, src, num);
            if (result == strlen(expected) && memcmp(actual, expected, num) == 0)
                tstcheck(true, "ft_strlcat OK for num=%u", num);
            else
                tstcheck(false, "ft_strlcat mismatch for num=%u", num);
            free(actual);
            free(expected);
            free(dst);
            free(src);
        }
    }
}