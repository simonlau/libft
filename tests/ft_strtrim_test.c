#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#include "test.h"

tstsuite("ft_strtrim") {
    tstcase("property set+s1+set matches ft_strtrim(s1,set) oracle") {
        char	*s1;
        char	*set;
        char	*actual;
        char	*result;
        char	*expected;
		size_t	total_len;
		int		i;
		int		match;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s1 = make_rand_str();
            set = make_rand_str();
            if (s1 == NULL || set == NULL)
            {
                free(s1);
                free(set);
                continue ;
            }
            total_len = 1 + strlen(s1) + 2 * strlen(set);
            actual = malloc(total_len);
            if (actual == NULL)
            {
                free(s1);
                free(set);
                continue ;
            }
            snprintf(actual, total_len, "%s%s%s", set, s1, set);
            result = ft_strtrim(actual, set);
            expected = ft_strtrim(s1, set);
            if (result == NULL && expected == NULL)
                match = 1;
            else if (result == NULL || expected == NULL)
                match = 0;
            else
                match = (strcmp(result, expected) == 0);
            tstexpect(match,
                "ft_strtrim(%s%s%s,%s) != ft_strtrim(%s,%s)",
                set, s1, set, set, s1, set);
            free(actual);
            free(result);
            free(expected);
            free(s1);
            free(set);
        }
    }

    tstcase("edge all-trimmed returns fresh empty string, not NULL") {
        const char	*s1;
        const char	*set;
        char		*result;

        struct {
            const char	*s;
            const char	*set;
        } cases[] = {
            { "",       "" },
            { "   ",    " " },
            { "\t\n",   " \t\n" },
            { "abba",   "ab" },
            { "xxxyxx", "xy" },
        };
        size_t n = sizeof(cases) / sizeof(cases[0]);

        for (size_t i = 0; i < n; i++) {
            s1 = cases[i].s;
            set = cases[i].set;
            result = ft_strtrim(s1, set);
            tstexpect(result != NULL && result[0] == '\0',
                "ft_strtrim(\"%s\", \"%s\") must return fresh empty string, got %p",
                s1, set, (void *)result);
            free(result);
        }
    }
}
