#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstsize") {
    tstcase("size counts nodes after adds") {
        int		i;
		char	*a;
		char	*b;
		char	*c;
		t_list	*head;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            a = make_rand_str();
            b = make_rand_str();
            c = make_rand_str();
            head = NULL;
            tstexpect(ft_lstsize(head) == 0, "ft_lstsize: empty list");
            head = ft_lstnew(a);
            tstexpect(ft_lstsize(head) == 1, "ft_lstsize: one node");
            ft_lstadd_front(&head, ft_lstnew(b));
            tstexpect(ft_lstsize(head) == 2, "ft_lstsize: two nodes");
            ft_lstadd_front(&head, ft_lstnew(c));
            tstexpect(ft_lstsize(head) == 3, "ft_lstsize: three nodes");
            ft_lstclear(&head, noop);
            free(a);
            free(b);
            free(c);
        }
    }
}
