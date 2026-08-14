#include "libft.h"
#include "theft.h"
#include <ctype.h>
#include <limits.h>

static enum theft_trial_res	prop_oracle(struct theft *t, void *arg)
{
	char	c;
	int		result;
	int		expected;

	(void)t;
	c = *(const char *)arg;
	result = ft_isdigit(c);
	expected = isdigit((unsigned char)c);
	if (expected == result)
	{
		return (THEFT_TRIAL_PASS);
	}
	return (THEFT_TRIAL_FAIL);
}

static enum theft_alloc_res	valid_char_alloc(struct theft *t, void *env,
		void **instance)
{
	int			*c;
	u_int64_t	choice;

	(void)env;
	c = malloc(sizeof(*c));
	if (c == NULL)
		return (THEFT_ALLOC_ERROR);
	choice = theft_random_choice(t, UCHAR_MAX + 1);
	if (choice == UCHAR_MAX)
		*c = EOF; /* EOF = -1 */
	else
	{
		*c = choice;
	}
	*instance = c;
	return (THEFT_ALLOC_OK);
}

static struct theft_type_info	valid_char_info = {
	.alloc = valid_char_alloc,
	.free = theft_generic_free_cb,
};

int	main(void)
{
	enum theft_run_res	res;

	struct theft_run_config cfg = {
		.name = __FILE_NAME__,
		.prop1 = prop_oracle,
		.type_info = {&valid_char_info},
		.trials = 500,
	};
	res = theft_run(&cfg);
	if (res == THEFT_RUN_PASS)
	{
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
