#include "libft.h"
#include "registry.h"

int	ft_putchar_fd_test(void)
{
	/* TODO: implement test for ft_putchar_fd_test */
	return (EXIT_SUCCESS);
}

REGISTER_TEST(0, ft_putchar_fd_test)

#ifndef ALL_TESTS
int	main(void)
{
	return (ft_putchar_fd_test());
}
#endif
