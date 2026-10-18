#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_strlen") {
    tstcase("property test matches strlen oracle", i) {
        char *s;
        size_t result;
        size_t expected;
        
        srand(0);
        for (i = 0; i < 2000; i++) {
            s = malloc(1);
            if (s == NULL) continue;
            int len = rand() % 64;
            s = realloc(s, len + 1);
            if (s == NULL) continue;
            for (int j = 0; j < len; j++)
                s[j] = (char)(rand() % 95 + 32);
            s[len] = '\0';
            result = ft_strlen(s);
            expected = strlen(s);
            if (expected == result)
                tstcheck(true, "ft_strlen(%s) = %zu = %zu", s, result, expected);
            else
                tstcheck(false, "ft_strlen(%s) = %zu != %zu", s, result, expected);
            free(s);
        }
    }
}