/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 08:34:20 by luciano           #+#    #+#             */
/*   Updated: 2026/03/08 10:57:39 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_validation(char *str, int **size)
{
	int	flag;

	flag = 0;
	if (!ft_digit_sign(str))
		return (0);
	while(*str)
	{
		if (*str == ' ' && !ft_digit_sign(str + 1))
			return (0);
		if (ft_sign(str) && !ft_isdigit(str + 1))
			return (0);
		if (ft_isdigit(str++))
		{
			if (!ft_isdigit(str) && *str != ' ')
				if (*str != '\0')
					return (0);
			if (flag == 0)
				**size += 1;
			flag = 1;
		}
		else
			flag = 0;
	}
	return (1);
}

int intjoin(char *str, int size, int **input, int i)
{
	long	number;

	while (i < size)
	{
		number = ft_atoi(str);
		if (number > 2147483647 || number < -2147483648)
			return (0);
		(*input)[i++] = number;
		while (*str != ' ')
			str++;
		str++;
	}
	return (1);
}
