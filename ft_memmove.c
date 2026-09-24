/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/09/24 21:02:52 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest_ptr;
	char	*src_ptr;
	int		pos;

	dest_ptr = (char *)dst;
	src_ptr = (char *)src;
	i = 0;
	while (i < len)
	{
		if (dst < src)
		{
			dest_ptr[i] = src_ptr[i];
		}
		else
		{
			pos = len - i - 1;
			dest_ptr[pos] = src_ptr[pos];
		}
		i++;
	}
	return (dst);
}
