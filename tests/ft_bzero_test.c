#include "libft.h"
#include "registry.h"

int	ft_bzero_test(void)
{
	/* TODO: implement test for ft_bzero_test */
	return (EXIT_SUCCESS);
}

REGISTER_TEST(0, ft_bzero_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_bzero_test());
}
#endif
