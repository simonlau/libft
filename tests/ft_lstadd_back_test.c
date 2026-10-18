#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstadd_back") {
    tstcase("add_back appends and size increments") {
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
            tstexpect(ft_lstsize(head) == 0, "ft_lstadd_back: empty list");
            ft_lstadd_back(&head, ft_lstnew(a));
            tstexpect(ft_lstsize(head) == 1, "ft_lstadd_back: one node");
            ft_lstadd_back(&head, ft_lstnew(b));
            tstexpect(ft_lstsize(head) == 2, "ft_lstadd_back: two nodes");
            ft_lstadd_back(&head, ft_lstnew(c));
            tstexpect(ft_lstsize(head) == 3, "ft_lstadd_back: three nodes");
            ft_lstclear(&head, noop);
            free(a);
            free(b);
            free(c);
        }
    }
}
