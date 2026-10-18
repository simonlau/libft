#include "libft.h"
#include <stdlib.h>
#include <stdint.h>
#include "test.h"

static void	del_noop(void *content)
{
	(void)content;
}

char	*make_rand_str(void)
{
	char	*s;
	int		len;

	s = malloc(1);
	if (s == NULL)
		return (NULL);
	len = rand() % 64;
	s = realloc(s, len + 1);
	if (s == NULL)
		return (NULL);
	for (int j = 0; j < len; j++)
		s[j] = (char)(rand() % 95 + 32);
	s[len] = '\0';
	return (s);
}

t_list	*make_lst(int *arr, int size)
{
	t_list	*head;
	t_list	*node;
	int		i;

	head = NULL;
	i = 0;
	while (i < size)
	{
		node = ft_lstnew((void *)(intptr_t)arr[i]);
		if (node == NULL)
		{
			ft_lstclear(&head, del_noop);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}
