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

tstsuite("ft_strlen")
{
	char	*s;
	size_t	result;
	size_t	expected;
	int		i;
	char	*tstdata[] = {"", "x", "abc\0def"};

	srand(SEED);
	tstcase("property test matches strlen oracle")
	{
		for (i = 0; i < TRIALS; i++)
		{
			s = make_rand_str();
			tstexpect((expected = strlen(s)) == (result = ft_strlen(s)),
				"ft_strlen(%s) = %zu != %zu", s, result, expected);
			free(s);
		}
	}
	tstcase("check special cases")
	{
		tstsection("Check bounds")
		{
			tstexpect((expected = strlen(tstcurdata)) == (result = ft_strlen(tstcurdata)),
				"ft_strlen(%s) = %zu != %zu", s, result, expected);
		}
	}
}
