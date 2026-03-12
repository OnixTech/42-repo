/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 09:02:56 by luciano           #+#    #+#             */
/*   Updated: 2026/03/12 16:09:18 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_validation(int arg, char **str, t_data *stack)
{
	int	i;
	int	k;

	i = 1;
	while (i < arg)
	{
		k = 0;
		if (!str[i][k])
			return (0);
		while (str[i][k])
		{
			if (ft_sign(&str[i][k]) && k == 0)
				k++;
			if (!ft_isdigit(&str[i][k]))
				return (0);
			k++;
		}
		i++;
	}
	stack->capacity = arg - 1;
	return (1);
}

int	arg_intjoin(char **str, t_data *stack)
{
	int		i;
	long	number;

	i = 0;
	while (i < stack->capacity)
	{
		number = ft_atoi(str[i + 1]);
		if (number > 2147483647 || number < -2147483648)
			return (0);
		if (duplicate_input(i, number, stack))
			return (0);
		stack->a[i++] = number;
	}
	return (1);
}
