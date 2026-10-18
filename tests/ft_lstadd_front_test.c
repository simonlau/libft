#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstadd_front") {
    tstcase("add_front increments size 0→1→2→3") {
        int		i;
		int		val;
		t_list	*head;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            head = NULL;
            tstexpect(ft_lstsize(head) == 0, "ft_lstadd_front: empty list");
            val = rand();
            ft_lstadd_front(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstsize(head) == 1, "ft_lstadd_front: one node");
            val = rand();
            ft_lstadd_front(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstsize(head) == 2, "ft_lstadd_front: two nodes");
            val = rand();
            ft_lstadd_front(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstsize(head) == 3, "ft_lstadd_front: three nodes");
            ft_lstclear(&head, noop);
        }
    }
}
