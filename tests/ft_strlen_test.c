#include "libft.h"
#include "registry.h"

int	ft_strlen_test(void)
{
	/* TODO: implement test for ft_strlen_test */
	return (EXIT_SUCCESS);
}

REGISTER_TEST(0, ft_strlen_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_strlen_test());
}
#endif
