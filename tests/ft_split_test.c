#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#include "test.h"

static void	free_result(char **result)
{
	int	i;

	if (result == NULL)
		return ;
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

tstsuite("ft_split") {
    tstcase("property cc s1 cc s2 cc splits into [s1, s2, NULL]") {
        char	*s1;
        char	*s2;
        char	c;
        char	**result;
        char	*combined;
        size_t	len;
        int		i;
        int		ok;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            s1 = make_rand_str();
            s2 = make_rand_str();
            if (s1 == NULL || s2 == NULL)
            {
                free(s1);
                free(s2);
                continue ;
            }
            if (*s1 == '\0' || *s2 == '\0')
            {
                free(s1);
                free(s2);
                continue ;
            }
            c = (unsigned char)rand();
            if (strchr(s1, c) != NULL || strchr(s2, c) != NULL)
            {
                free(s1);
                free(s2);
                continue ;
            }
            len = 6 + strlen(s1) + strlen(s2) + 1;
            combined = malloc(len);
            if (combined == NULL)
            {
                free(s1);
                free(s2);
                continue ;
            }
            snprintf(combined, len, "%c%c%s%c%c%s%c%c",
                     c, c, s1, c, c, s2, c, c);
            result = ft_split(combined, c);
            ok = 1;
            if (result == NULL)
                ok = 0;
            else if (strcmp(result[0], s1) != 0
                     || strcmp(result[1], s2) != 0
                     || result[2] != NULL)
                ok = 0;
            tstexpect(ok,
                "ft_split(%c%c%s%c%c%s%c%c, %c) != {%s, %s, NULL}",
                c, c, s1, c, c, s2, c, c, c, s1, s2);
            if (result != NULL)
                free_result(result);
            free(combined);
            free(s1);
            free(s2);
        }
    }
}
