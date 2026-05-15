/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 08:34:20 by luciano           #+#    #+#             */
/*   Updated: 2026/04/13 13:52:44 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_validation(char *str, t_data *stack)
{
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (*str && !ft_digit_sign(str))
			return (0);
		if (ft_sign(str) && !ft_isdigit(str + 1))
			return (0);
		if (ft_digit_sign(str))
		{
			stack->capacity += 1;
			str++;
		}
		while (ft_isdigit(str))
			str++;
		if (!ft_isdigit(str) && *str != ' ')
			if (*str != '\0')
				return (0);
	}
	return (1);
}

int	str_intjoin(char *str, t_data *stack)
{
	long	number;
	int		i;

	i = 0;
	while (*str && i < stack->capacity)
	{
		while (*str && *str == ' ')
			str++;
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
	}
	return (1);
}
