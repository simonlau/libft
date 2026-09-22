#include "libft.h"
#include "registry.h"

int	ft_memset_test(void)
{
	/* TODO: implement test for ft_memset_test */
	return (EXIT_SUCCESS);
}

REGISTER_TEST(0, ft_memset_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_memset_test());
}
#endif
