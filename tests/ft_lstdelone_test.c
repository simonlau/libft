#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include "test.h"

static void	noop(void *content)
{
	(void)content;
}

tstsuite("ft_lstdelone") {
    tstcase("lstdelone frees a single node without crashing") {
        int		i;
		char	*str;
		t_list	*result;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            str = make_rand_str();
            result = ft_lstnew(str);
            if (result != NULL)
            {
                tstexpect(result->content == str, "ft_lstdelone: content");
                ft_lstdelone(result, noop);
            }
            free(str);
        }
    }
}
