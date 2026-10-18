#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>

tstsuite("ft_strjoin") {
    tstcase("joins two non-empty strings") {
        const char *s1 = "abc";
        const char *s2 = "def";
        char *result;

        result = ft_strjoin(s1, s2);
        tstexpect(result != NULL, "ft_strjoin NULL");
        if (result != NULL) {
            tstexpect(strcmp(result, "abcdef") == 0, "ft_strjoin content");
            free(result);
        }
    }

    tstcase("empty strings join to empty") {
        char *left;
        char *right;

        left = ft_strjoin("", "");
        right = ft_strjoin("", "");
        tstexpect(left != NULL && right != NULL, "edge case NULL");
        if (left != NULL && right != NULL) {
            tstexpect(strcmp(left, "") == 0 && strcmp(left, right) == 0,
                     "edge case failed: empty join");
            free(left);
            free(right);
        }
    }
}
