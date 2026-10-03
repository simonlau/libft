/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/03 14:11:00 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*result;
	size_t	i;

	s_len = ft_strlen(s);
	if (s_len == 0 || start > s_len)
	{
		result = ft_calloc(1, 1);
		if (result == NULL)
			return (NULL);
		else
			return (result);
	}
	if (len > s_len - start)
		len = s_len - start;
	result = ft_calloc((1 + len), sizeof(*result));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[i + start];
		i++;
	}
	return (result);
}
