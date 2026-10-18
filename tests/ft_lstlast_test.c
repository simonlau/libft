#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstlast") {
    tstcase("last returns the tail node") {
        int		i;
		char	*a;
		char	*b;
		char	*c;
		t_list	*head;
		t_list	*last;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            a = make_rand_str();
            b = make_rand_str();
            c = make_rand_str();
            head = NULL;
            tstexpect(ft_lstlast(head) == NULL, "ft_lstlast: empty list");
            ft_lstadd_front(&head, ft_lstnew(a));
            tstexpect(ft_lstlast(head) == head, "ft_lstlast: one node");
            last = head;
            ft_lstadd_front(&head, ft_lstnew(b));
            tstexpect(ft_lstlast(head) == last, "ft_lstlast: two nodes");
            ft_lstadd_front(&head, ft_lstnew(c));
            tstexpect(ft_lstlast(head) == last, "ft_lstlast: three nodes");
            ft_lstclear(&head, noop);
            free(a);
            free(b);
            free(c);
        }
    }
}
