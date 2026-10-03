/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/03 13:12:27 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_groups(char c, const char *str)
{
	size_t	count;

	count = 0;
	while (str != NULL && *str != '\0')
	{
		if (*str == c)
		{
			count++;
		}
		str++;
	}
	return (count);
}

static void	freeUsed(char **result, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static void	handleLastWord(char **result, int i, const char *current_letter)
{
	result[i] = ft_strdup(current_letter);
	if (!result[i])
	{
		freeUsed(result, i);
		return ;
	}
	result[i + 1] = NULL;
}

static void	split(const char *trim_str, char c, size_t numSep, char **result)
{
	size_t		i;
	const char	*current_letter;
	char		*next;

	i = 0;
	current_letter = trim_str;
	while (i < numSep)
	{
		next = ft_strchr(current_letter, c);
		if (next == NULL)
			break ;
		result[i] = malloc((next - current_letter + 1) * sizeof(**result));
		if (!result[i])
		{
			freeUsed(result, i);
			return ;
		}
		ft_strlcpy(result[i], current_letter, next - current_letter + 1);
		current_letter = next + 1;
		i++;
	}
	handleLastWord(result, i, current_letter);
}

char	**ft_split(const char *str, char c)
{
	char	*trim_str;
	size_t	numSep;
	char	**result;
	char	set[] = {c, '\0'};

	trim_str = ft_strtrim(str, set);
	if (!trim_str)
		return (NULL);
	numSep = count_groups(c, trim_str);
	result = malloc((1 + 1 + numSep) * sizeof(*result));
	if (!result)
	{
		free(trim_str);
		return (NULL);
	}
	split(trim_str, c, numSep + 1, result);
	free(trim_str);
	return (result);
}
