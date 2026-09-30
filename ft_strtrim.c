/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/09/30 16:53:22 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*end;
	char		*result;

	if (ft_strlen(s1) == 0 || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	end = s1 + ft_strlen(s1) - 1;
	while (*s1 != '\0')
	{
		if (ft_strchr(set, *s1) == NULL)
			break ;
		s1++;
	}
	while (end > s1)
	{
		if (ft_strchr(set, *end) == NULL)
			break ;
		end--;
	}
	result = ft_calloc(2 + end - s1, sizeof(*result));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, 2 + end - s1);
	return (result);
}
