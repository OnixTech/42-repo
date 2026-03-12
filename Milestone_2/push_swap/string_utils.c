/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 08:34:20 by luciano           #+#    #+#             */
/*   Updated: 2026/03/12 16:09:23 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_validation(char *str, t_data *stack)
{
	int	flag;

	flag = 0;
	if (!ft_digit_sign(str))
		return (0);
	while (*str)
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
				stack->capacity += 1;
			flag = 1;
		}
		else
			flag = 0;
	}
	return (1);
}

int	str_intjoin(char *str, t_data *stack)
{
	long	number;
	int		i;

	i = 0;
	while (i < stack->capacity)
	{
		number = ft_atoi(str);
		if (number > 2147483647 || number < -2147483648)
			return (0);
		if (duplicate_input(i, number, stack))
			return (0);
		stack->a[i++] = number;
		while (ft_digit_sign(str))
			str++;
		if (*str == '\0')
			break ;
		str++;
	}
	return (1);
}
