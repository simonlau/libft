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

tstsuite("ft_strchr")
{
	char	*s;
	int		c;
	char	*expected;
	char	*result;
	int		i;
	char	*tstdata[] = {"", "x", "abc", "hello world", "abc\0def"};

	srand(SEED);
	tstcase("property test matches strchr oracle")
	{
		for (i = 0; i < TRIALS; i++)
		{
			s = make_rand_str();
			c = rand() % 256;
			tstexpect((expected = strchr(s, c)) == (result = ft_strchr(s, c)),
				"ft_strchr(%s, %d)", s, c);
			free(s);
		}
	}
	tstcase("check special cases")
	{
		tstsection("Check bounds")
		{
			c = rand() % 256;
			tstexpect((expected = strchr(tstcurdata, c)) == (result = ft_strchr(tstcurdata, c)),
				"ft_strchr(%s, %d)", tstcurdata, c);
		}
	}
}
