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

tstsuite("ft_strlcat")
{
	char	*dst;
	char	*src;
	size_t	num;
	char	*actual;
	char	*expected;
	size_t	result;
	size_t	expected_result;
	int		i;
	char	*tstdata[] = {"", "x", "abc", "hello world"};

	srand(SEED);
	tstcase("property test matches strlcat oracle")
	{
		for (i = 0; i < TRIALS; i++)
		{
			dst = make_rand_str();
			src = make_rand_str();
			num = rand() % 32 + 1;
			actual = calloc(num, sizeof(*actual));
			if (actual == NULL)
			{
				free(dst);
				free(src);
				continue;
			}
			snprintf(actual, num, "%s", dst);
			expected = calloc(num, sizeof(*expected));
			if (expected == NULL)
			{
				free(actual);
				free(dst);
				free(src);
				continue;
			}
			snprintf(expected, num, "%s", dst);
			result = ft_strlcat(actual, src, num);
			expected_result = strlcat(expected, src, num);
			tstexpect(result == expected_result && memcmp(actual, expected, num) == 0,
				"ft_strlcat mismatch for num=%zu", num);
			free(actual);
			free(expected);
			free(dst);
			free(src);
		}
	}
	tstcase("check special cases")
	{
		tstsection("Check bounds")
		{
			num = rand() % 32 + 1;
			actual = calloc(num, sizeof(*actual));
			if (actual == NULL)
				continue;
			snprintf(actual, num, "%s", tstcurdata);
			expected = calloc(num, sizeof(*expected));
			if (expected == NULL)
			{
				free(actual);
				continue;
			}
			snprintf(expected, num, "%s", tstcurdata);
			result = ft_strlcat(actual, tstcurdata, num);
			expected_result = strlcat(expected, tstcurdata, num);
			tstexpect(result == expected_result && memcmp(actual, expected, num) == 0,
				"ft_strlcat(%s, %zu)", tstcurdata, num);
			free(actual);
			free(expected);
		}
	}
}
