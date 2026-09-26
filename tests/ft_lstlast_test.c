#include "libft.h"
#include "registry.h"
#include "theft.h"

static enum theft_trial_res	prop_lstlast(struct theft *t, void *arg)
{
	(void)t;
	(void)arg;
	return (THEFT_TRIAL_PASS);
}

int	ft_lstlast_test(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.prop1 = prop_lstlast,
		.name = __FILE__,
		.trials = 100,
		.type_info = {theft_get_builtin_type_info(THEFT_BUILTIN_uint)},
	};
	res = theft_run(&cfg);
	if (res != THEFT_RUN_PASS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

REGISTER_TEST(0, ft_lstlast_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_lstlast_test());
}
#endif
