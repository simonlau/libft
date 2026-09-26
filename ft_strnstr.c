/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/09/26 21:51:02 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	pos;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	pos = 0;
	while (haystack[i] != '\0' && i < len)
	{
		pos = 0;
		while (haystack[i + pos] != '\0' && i + pos < len && haystack[i
			+ pos] == needle[pos])
		{
			pos++;
		}
		if (needle[pos] == '\0')
		{
			return (char *)(haystack + i);
		}
		i++;
	}
	return (NULL);
}
