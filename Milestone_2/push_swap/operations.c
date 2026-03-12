/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:28:03 by luciano           #+#    #+#             */
/*   Updated: 2026/03/12 19:36:01 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_data *stack)
{
	int	container;

	if (stack->size_a > 1)
	{
		container = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = container;
	}
}

void sb(t_data *stack)
{
	int	container;

	if (stack->size_b > 1)
	{
		container = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = container;
	}
}

void	ss(t_data *stack)
{
	sa(stack);
	sb(stack);
}

void	pa(t_data *stack)
{
	if (stack->size_b > 0)
	{
		shift_down(stack->a, stack->size_a);
		stack->a[0] = stack->b[0];
		stack->size_a += 1;
		shift_up(stack->b, stack->size_b);
		stack->size_b -= 1;
		stack->b[stack->size_b] = 0;
	}
}

void	pb(t_data *stack)
{
	if (stack->size_a > 0)
	{
		shift_down(stack->b, stack->size_b);
		stack->b[0] = stack->a[0];
		stack->size_b += 1;
		shift_up(stack->a, stack->size_a);
		stack->size_a -= 1;
		stack->a[stack->size_a] = 0;
	}
}
