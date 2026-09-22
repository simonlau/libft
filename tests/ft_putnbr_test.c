#include "libft.h"
#include "registry.h"

int	ft_putnbr_test(void)
{
	/* TODO: implement test for ft_putnbr_test */
	return (EXIT_SUCCESS);
}

REGISTER_TEST(0, ft_putnbr_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_putnbr_test());
}
#endif
