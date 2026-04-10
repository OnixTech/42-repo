/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:19:35 by luciano           #+#    #+#             */
/*   Updated: 2026/04/10 20:02:26 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks(t_data *stack)
{
	int ch_size;

	ch_size = chunk_size(stack);
	push_chunk_b(stack, ch_size);
	//push_chunk_a(stack, ch_size);
}

void	push_chunk_b(t_data *stack, int  ch_size)
{
	int	start;
	int	end;

	start = 0;
	end = ch_size - 1;
	while (stack->size_a > 5)
	{
		while (stack->size_a > 5 && exist_range(stack, start, end))
			chunk_bottom(stack, start, end);
		//start = end + 1;
		//end = start + (ch_size / 2) - 1;
		//while (stack->size_a > 5 && exist_range(stack, start, end))
		//	chunk_top(stack, start, end);
		start = end + 1;
		end = start + ch_size - 1;
		if (end >= stack->capacity)
			end = stack->capacity - 1;
	}
	if (stack->a[1] != stack->a[0] + 1)
		if (stack->a[0] != stack->capacity - 1)
			pb(stack);
}

int	exist_range(t_data *stack, int start, int end)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] >= start && stack->a[i] <= end)
			return (1);
		i++;
	}
	return (0);
}

void	chunk_bottom(t_data *stack, int start, int end)
{
	int	i;
	int	j;

	index_positions(stack, start, end, &i, &j);
	push_cheapest(stack, i, j);
}

void	chunk_top(t_data *stack, int start, int end)
{
	int	i;
	int	j;

	index_positions(stack, start, end, &i, &j);
	push_cheapest(stack, i, j);
}
