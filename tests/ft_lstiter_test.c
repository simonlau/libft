#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static int	g_calls;

static void	change(void *content)
{
	(void)content;
	g_calls++;
}

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstiter") {
    tstcase("iter invokes callback once per node") {
        int		i;
		t_list	*head;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            head = make_rand_lst(3);
            g_calls = 0;
            ft_lstiter(head, change);
            tstexpect(g_calls == 3, "ft_lstiter: callback called 3 times");
            ft_lstclear(&head, noop);
        }
    }
}
