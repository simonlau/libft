/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/04 16:39:49 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	len;

	if (size != 0 && count > SIZE_MAX / size)
	{
		errno = EINVAL;
		return (NULL);
	}
	len = count * size;
	ptr = malloc(len);
	if (ptr == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memset(ptr, NULL_CHAR, len);
	return (ptr);
}
