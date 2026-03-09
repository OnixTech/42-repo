/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 08:34:20 by luciano           #+#    #+#             */
/*   Updated: 2026/03/09 08:24:55 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_validation(char *str, int *size)
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
				*size += 1;
			flag = 1;
		}
		else
			flag = 0;
	}
	return (1);
}

int str_intjoin(char *str, int size, int **input)
{
	long	number;
	int	i;
	int	k;

	i = 0;
	while (i < size)
	{
		number = ft_atoi(str);
		if (number > 2147483647 || number < -2147483648)
			return (0);
		if (i)
		{
			k = i;
			while (k--)
				if (number == (*input)[k])
					return (0);
		}
		(*input)[i++] = number;
		while (ft_digit_sign(str))
			str++;
		if (*str == '\0')
			break ;
		str++;
	}
	return (1);
}
