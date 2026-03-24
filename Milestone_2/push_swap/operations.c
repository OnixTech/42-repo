/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:28:03 by luciano           #+#    #+#             */
/*   Updated: 2026/03/24 10:18:08 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *stack)
{
	int	container;

	if (stack->size_a > 1)
	{
		container = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = container;
	}
	write(1, "sa\n", 3);
}

void	sb(t_data *stack)
{
	int	container;

	if (stack->size_b > 1)
	{
		container = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = container;
	}
	write(1, "sb\n", 3);
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
		shift_up(stack->b, stack->size_b);
		stack->size_a++;
		stack->size_b--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_data *stack)
{
	if (stack->size_a > 0)
	{
		shift_down(stack->b, stack->size_b);
		stack->b[0] = stack->a[0];
		shift_up(stack->a, stack->size_a);
		stack->size_b++;
		stack->size_a--;
		write(1, "pb\n", 3);
	}
}
