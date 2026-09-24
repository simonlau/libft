#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <string.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg)
{
	char	*str;
	char	*expected;
	char	*actual;
	char	*actual_dst;
	size_t	len;
	void	*result;

	(void)t;
	str = (char *)arg;
	len = strlen(str);
	expected = strdup(str);
	memmove(expected + 1, expected, len);
	actual = strdup(str);
	actual_dst = actual + 1;
	result = ft_memmove(actual_dst, actual, len);
	if (result == actual_dst && memcmp(actual, expected, len) == 0)
		return (THEFT_TRIAL_PASS);
	return (THEFT_TRIAL_FAIL);
}

int	ft_memmove_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop1 = prop_oracle,
		.name = __FILE__,
		.trials = 1000,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_char_ARRAY)},
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

REGISTER_TEST(0, ft_memmove_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_memmove_test());
}
#endif
