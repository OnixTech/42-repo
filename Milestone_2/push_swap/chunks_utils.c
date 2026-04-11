/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:45:34 by luciano           #+#    #+#             */
/*   Updated: 2026/04/11 17:21:11 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_size(t_data *stack)
{
	if (stack->size_a < 100)
		return (10);
	else if (stack->size_a < 500)
		return (30);
	else
		return (50);
}

void	push_cheapest(t_data *stack, int i, int j)
{
	int	cost_up;
	int	cost_down;

	cost_up = i;
	cost_down = stack->size_a - j;
	if (cost_up <= cost_down)
	{
		while (cost_up--)
			ra(stack);
		pb(stack);
		if (stack->size_b > 1 && stack->b[0] < stack->b[1])
			sb(stack);
	}
	else
	{
		while (cost_down--)
			rra(stack);
		pb(stack);
		if (stack->size_b > 1 && stack->b[0] < stack->b[1])
			sb(stack);
	}
}

int	exist_range(t_data *stack, int start, int end)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] >= start && stack->a[i] <= end)
			if (stack->a[i] != stack->capacity - 1)
				return (1);
		i++;
	}
	return (0);
}
/*
void stack_ab(t_data *stack, int a)
{
	int 	i;

	i = 0;
	if (!a)
	{
		printf("stack a -> ");
		while (stack->size_a && i < stack->size_a)
			printf("%d ", stack->a[i++]);
	}
	else
	{
		printf("stack b -> ");
		while (stack->size_b && i < stack->size_b)
			printf("%d ", stack->b[i++]);
	}
	printf("\n");
}
*/
