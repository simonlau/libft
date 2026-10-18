#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstclear") {
    tstcase("clear empties the list and NULLs the head") {
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
            ft_lstclear(&head, noop);
            tstexpect(ft_lstsize(head) == 0 && head == NULL,
                     "ft_lstclear: empty list");
            ft_lstadd_front(&head, ft_lstnew(a));
            ft_lstadd_front(&head, ft_lstnew(b));
            ft_lstadd_front(&head, ft_lstnew(c));
            ft_lstclear(&head, noop);
            tstexpect(ft_lstsize(head) == 0 && head == NULL,
                     "ft_lstclear: non-empty list");
            free(a);
            free(b);
            free(c);
        }
    }
}
