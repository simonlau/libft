/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:39:55 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/06 17:14:09 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static long	ft_abs(int n)
{
	if (n < 0)
	{
		return (-(long)n);
	}
	return ((long)n);
}

static size_t	countDigits(long num, int negativeSign)
{
	int	CURRENT_DIGIT_SPACE;
	int	MINUS_SIGN_SPACE;

	CURRENT_DIGIT_SPACE = 1;
	if (num < 10)
	{
		if (negativeSign)
		{
			MINUS_SIGN_SPACE = 1;
			return (CURRENT_DIGIT_SPACE + MINUS_SIGN_SPACE);
		}
		return (CURRENT_DIGIT_SPACE);
	}
	return (CURRENT_DIGIT_SPACE + countDigits(num / 10, negativeSign));
}

static char	digitToChar(int digit)
{
	if (digit > 9 || digit < 0)
	{
		return (NULL_CHAR);
	}
	return (digit + '0');
}

char	*ft_itoa(int n)
{
	char	*result;
	int		negativeSign;
	size_t	len;
	size_t	i;
	long	num;

	num = ft_abs(n);
	if (n < 0)
		negativeSign = 1;
	else
		negativeSign = 0;
	len = countDigits(num, negativeSign);
	result = malloc(len + NULL_CHAR_ALLOC * sizeof(*result));
	if (!result)
		return (NULL);
	result[len] = NULL_CHAR;
	i = 0;
	while (i < len)
	{
		result[len - NULL_CHAR_ALLOC - i] = digitToChar(num % 10);
		num /= 10;
		i++;
	}
	if (negativeSign == 1)
		result[0] = '-';
	return (result);
}
