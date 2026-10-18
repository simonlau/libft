#include "libft.h"
#include "test.h"
#include "tst.h"
#include <stdlib.h>
#include <string.h>
#if defined(__GLIBC__)
# include <bsd/string.h>
#endif

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

tstsuite("ft_strlcpy")
{
	char	*str;
	size_t	num;
	char	*actual;
	char	*expected;
	size_t	result;
	size_t	expected_result;
	int		i;
	char	*tstdata[] = {"", "x", "abc", "hello world"};

	srand(SEED);
	tstcase("property test matches strlcpy oracle")
	{
		for (i = 0; i < TRIALS; i++)
		{
			str = make_rand_str();
			num = rand() % 64;
			actual = calloc(num + 1, sizeof(*actual));
			if (actual == NULL)
				continue;
			expected = calloc(num + 1, sizeof(*expected));
			if (expected == NULL)
			{
				free(actual);
				free(str);
				continue;
			}
			result = ft_strlcpy(actual, str, num);
			expected_result = strlcpy(expected, str, num);
			tstexpect(result == expected_result && memcmp(actual, expected, num) == 0,
				"ft_strlcpy mismatch for len=%zu", num);
			free(actual);
			free(expected);
			free(str);
		}
	}
	tstcase("check special cases")
	{
		tstsection("Check bounds")
		{
			num = rand() % 64;
			actual = calloc(num + 1, sizeof(*actual));
			if (actual == NULL)
				continue;
			expected = calloc(num + 1, sizeof(*expected));
			if (expected == NULL)
			{
				free(actual);
				continue;
			}
			result = ft_strlcpy(actual, tstcurdata, num);
			expected_result = strlcpy(expected, tstcurdata, num);
			tstexpect(result == expected_result && memcmp(actual, expected, num) == 0,
				"ft_strlcpy(%s, %zu)", tstcurdata, num);
			free(actual);
			free(expected);
		}
	}
}
