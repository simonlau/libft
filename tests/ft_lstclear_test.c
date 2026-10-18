#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstclear") {
    tstcase("clear empties the list and NULLs the head") {
        int		i;
		int		val;
		t_list	*head;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            head = NULL;
            ft_lstclear(&head, noop);
            tstexpect(ft_lstsize(head) == 0 && head == NULL,
                     "ft_lstclear: empty list");
            val = rand();
            ft_lstadd_front(&head, ft_lstnew((void *)(intptr_t)val));
            val = rand();
            ft_lstadd_front(&head, ft_lstnew((void *)(intptr_t)val));
            val = rand();
            ft_lstadd_front(&head, ft_lstnew((void *)(intptr_t)val));
            ft_lstclear(&head, noop);
            tstexpect(ft_lstsize(head) == 0 && head == NULL,
                     "ft_lstclear: non-empty list");
        }
    }
}
