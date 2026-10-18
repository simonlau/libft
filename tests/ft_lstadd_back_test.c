#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstadd_back") {
    tstcase("add_back appends and size increments") {
        int		i;
		int		val;
		t_list	*head;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            head = NULL;
            tstexpect(ft_lstsize(head) == 0, "ft_lstadd_back: empty list");
            val = rand();
            ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstsize(head) == 1, "ft_lstadd_back: one node");
            val = rand();
            ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstsize(head) == 2, "ft_lstadd_back: two nodes");
            val = rand();
            ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)val));
            tstexpect(ft_lstsize(head) == 3, "ft_lstadd_back: three nodes");
            ft_lstclear(&head, noop);
        }
    }
}
