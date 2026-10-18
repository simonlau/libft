#include "libft.h"
#include "test.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>

static char	*make_rand_str(void)
{
	char	*s;
	int		len;

	s = malloc(1);
	if (s == NULL)
		return (NULL);
	len = rand() % 64;
	s = realloc(s, len + 1);
	if (s == NULL)
		return (NULL);
	for (int j = 0; j < len; j++)
		s[j] = (char)(rand() % 95 + 32);
	s[len] = '\0';
	return (s);
}

tstsuite("ft_strrchr")
{
	char	*s;
	int		c;
	char	*expected;
	char	*result;
	int		i;
	char	*tstdata[] = {"", "x", "abc", "hello world", "abc\0def"};

	srand(SEED);
	tstcase("property test matches strrchr oracle")
	{
		for (i = 0; i < TRIALS; i++)
		{
			s = make_rand_str();
			c = rand() % 256;
			tstexpect((expected = strrchr(s, c)) == (result = ft_strrchr(s, c)),
				"ft_strrchr(%s, %d)", s, c);
			free(s);
		}
	}
	tstcase("check special cases")
	{
		tstsection("Check bounds")
		{
			c = rand() % 256;
			tstexpect((expected = strrchr(tstcurdata, c)) == (result = ft_strrchr(tstcurdata, c)),
				"ft_strrchr(%s, %d)", tstcurdata, c);
		}
	}
}
