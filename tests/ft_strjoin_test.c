#include "../libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_strjoin") {
    tstcase("property test matches join oracle", i) {
        const char *s1;
        const char *s2;
        char *result;
        char *another;
        size_t rlen;
        a_len;
        a_len = strlen(s1) + strlen(s2);
        result = ft_strjoin(s1, s2);
        if (result == NULL) { tstcheck(false, "ft_strjoin NULL"); return; }
        rlen = strlen(result);
        if (rlen != a_len) { free(result); tstcheck(false, "wrong length"); return; }
        another = ft_strjoin(s2, s1);
        if (strlen(result) != strlen(another)) { free(result); free(another); tstcheck(false, "len mismatch"); return; }
        tstcheck(true, "ft_strjoin OK");
        free(result);
        free(another);
    }
}

static const char *one[] = {"abc", "def", "ghi"};

tstsuite("ft_strjoin edge cases") {
    tstcase("empty string joins to empty", s1) {
        const char *empty = "";
        char *left;
        char *right;
        left = ft_strjoin("", s1);
        right = ft_strjoin(s1, "");
        if (strcmp(s1, left) != 0 || strcmp(left, right) != 0)
            tstcheck(false, "edge case failed: empty join");
        else
            tstcheck(true, "edge case OK");
        free(left);
        free(right);
    }
}