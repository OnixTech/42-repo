/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:50 by luciano           #+#    #+#             */
/*   Updated: 2026/03/13 10:50:58 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *stack)
{
	int	container;

	if (stack->size_a > 1)
	{
		container = stack->a[0];
		shift_up(stack->a, stack->size_a);
		stack->a[stack->size_a - 1] = container;
	}
}

void	rb(t_data *stack)
{
	int	container;

	if (stack->size_b > 1)
	{
		container = stack->b[0];
		shift_up(stack->b, stack->size_b);
		stack->b[stack->size_b - 1] = container;
	}
}

void	rra(t_data *stack)
{
	int	container;

	if (stack->size_a > 1)
	{
		container = stack->a[stack->size_a - 1];
		shift_down(stack->a, stack->size_a);
		stack->a[0] = container;
	}
}

void	rrb(t_data *stack)
{
	int	container;

	if (stack->size_b > 1)
	{
		container = stack->b[stack->size_b - 1];
		shift_down(stack->b, stack->size_b);
		stack->b[0] = container;
	}
}
