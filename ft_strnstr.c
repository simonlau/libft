/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/09/28 09:26:00 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	pos;
	char	curr;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	pos = 0;
	while (haystack[i] != '\0' && i < len)
	{
		pos = 0;
		curr = haystack[i + pos];
		while (curr != '\0' && i + pos < len && curr == needle[pos])
		{
			pos++;
			curr = haystack[i + pos];
		}
		if (needle[pos] == '\0')
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
