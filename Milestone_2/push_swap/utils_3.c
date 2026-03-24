/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:00:16 by luciano           #+#    #+#             */
/*   Updated: 2026/03/24 10:02:12 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_down(int *stack, int size)
{
	int	i;

	i = size;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
}

void	shift_up(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	rr(t_data *stack)
{
	ra(stack);
	rb(stack);
}

void	rrr(t_data *stack)
{
	rra(stack);
	rrb(stack);
}
