#include "libft.h"
#include "tst.h"
#include <stdlib.h>
#include "test.h"

tstsuite("ft_lstnew") {
    tstcase("new node holds content and NULL next") {
        int		i;
		char	*str;
		t_list	*result;

        srand(SEED);
        for (i = 0; i < TRIALS; i++) {
            str = make_rand_str();
            result = ft_lstnew(str);
            if (result != NULL)
            {
                tstexpect(result->content == str, "ft_lstnew: content mismatch");
                tstexpect(result->next == NULL, "ft_lstnew: next should be NULL");
                free(result);
            }
            free(str);
        }
    }
}
