#include "libft.h"
#include "registry.h"

int	ft_memalloc_test(void)
{
	/* TODO: implement test for ft_memalloc_test */
	return (EXIT_SUCCESS);
}

REGISTER_TEST(0, ft_memalloc_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_memalloc_test());
}
#endif
