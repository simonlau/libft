#include "libft.h"
#include "registry.h"
#include "theft.h"
#include <stdio.h>
#include <string.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg)
{
	char	*s;
	FILE	*file;
	char	*buf;
	size_t	n;

	(void)t;
	s = (char *)arg;
	file = open_memstream(&buf, &n);
	if (!file)
		return (THEFT_TRIAL_SKIP);
	ft_putstr_fd(s, fileno(file));
	fclose(file);
	if (memcmp(buf, s, n) == EQUAL)
	{
		free(buf);
		return (THEFT_TRIAL_PASS);
	}
	free(buf);
	return (THEFT_TRIAL_FAIL);
}

int	ft_putstr_fd_test(void)
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

REGISTER_TEST(1, ft_putstr_fd_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_putstr_fd_test());
}
#endif
