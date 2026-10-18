#include "libft.h"
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
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
		s[j] = (char)(rand() % 255 + 1);
	s[len] = '\0';
	return (s);
}

t_list	*make_rand_lst(int size)
{
	int		*arr;
	t_list	*head;
	t_list	*node;
	int		i;

	arr = make_rand_int_arr(size);
	if (arr == NULL)
		return (NULL);
	head = NULL;
	i = 0;
	while (i < size)
	{
		node = ft_lstnew((void *)(intptr_t)arr[i]);
		if (node == NULL)
		{
			ft_lstclear(&head, del_noop);
			free(arr);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		i++;
	}
	free(arr);
	return (head);
}

int	*make_rand_int_arr(int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * (size_t)size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = rand();
		i++;
	}
	return (arr);
}

/* Read up to `count` bytes from `fd` into `buf`.
 * Returns the number of bytes read, or -1 on read error. */
ssize_t	capture_begin(int fd, void *buf, size_t count)
{
	size_t	total;
	ssize_t	r;

	total = 0;
	while (total < count)
	{
		r = read(fd, buf + total, count - total);
		if (r == 0)
			break ;
		if (r < 0)
			return (-1);
		total += (size_t)r;
	}
	return ((ssize_t)total);
}

/* Drain any remaining bytes from `fd`, then close it.
 * Returns the number of extra bytes read. */
size_t	capture_end(int fd)
{
	char	discard[4096];
	ssize_t	r;
	size_t	extra;

	extra = 0;
	while (1)
	{
		r = read(fd, discard, sizeof(discard));
		if (r == 0)
			break ;
		if (r < 0)
			break ;
		extra += (size_t)r;
	}
	close(fd);
	return (extra);
}
