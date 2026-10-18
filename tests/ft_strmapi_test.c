#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#include "test.h"

static char	f_map(unsigned int i, char c)
{
	(void)i;
	(void)c;
	return ('?');
}

tstsuite("ft_strmapi") {
    tstcase("property maps every char to '?'") {
        char	*s;
        char	*result;
        char	*expected;
        int		i;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s = make_rand_str();
            if (s == NULL)
                continue ;
            result = ft_strmapi(s, f_map);
            expected = calloc(1 + strlen(s), sizeof(char));
            if (expected == NULL) {
                free(result);
                free(s);
                continue ;
            }
            memset(expected, '?', strlen(s));
            tstexpect(result != NULL && strcmp(expected, result) == 0,
                "ft_strmapi(%s) != all-'?'", s);
            free(result);
            free(expected);
            free(s);
        }
    }
}
