#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static int	g_calls;

static void	*change(void *content)
{
	g_calls++;
	return (content);
}

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstmap") {
    tstcase("map invokes function once per node") {
        int		i;
		int		arr[3];
		t_list	*head;
		t_list	*result;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            arr[0] = rand();
            arr[1] = rand();
            arr[2] = rand();
            head = make_lst(arr, 3);
            g_calls = 0;
            result = ft_lstmap(head, change, noop);
            if (result != NULL)
            {
                tstexpect(g_calls == 3, "ft_lstmap: function called 3 times");
                ft_lstclear(&result, noop);
            }
            ft_lstclear(&head, noop);
        }
    }
}
