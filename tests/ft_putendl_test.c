#include "libft.h"
#include "registry.h"

int	ft_putendl_test(void)
{
	/* TODO: implement test for ft_putendl_test */
	return (EXIT_SUCCESS);
}

REGISTER_TEST(0, ft_putendl_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_putendl_test());
}
#endif
