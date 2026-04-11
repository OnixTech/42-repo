/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:19:35 by luciano           #+#    #+#             */
/*   Updated: 2026/04/11 16:44:11 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks(t_data *stack)
{
	int	ch_size;

	ch_size = chunk_size(stack);
	push_chunk_b(stack, ch_size);
}

void	push_chunk_b(t_data *stack, int ch_size)
{
	int	start;
	int	end;

	start = 0;
	end = ch_size - 1;
	while (stack->size_a > 5)
	{
		while (stack->size_a > 5 && exist_range(stack, start, end))
			select_number(stack, start, end);
		start = end + 1;
		end = start + ch_size - 1;
		if (end >= stack->capacity)
			end = stack->capacity - 1;
	}
	if (stack->a[1] != stack->a[0] + 1)
		if (stack->a[0] != stack->capacity - 1)
			pb(stack);
}

void	select_number(t_data *stack, int start, int end)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stack->size_a / 2)
	{
		if (stack->a[i] >= start && stack->a[i] <= end)
			if (stack->a[i] != stack->capacity - 1)
				break ;
		i++;
	}
	j = stack->size_a - 1;
	while (j > stack->size_a / 2)
	{
		if (stack->a[j] >= start && stack->a[j] <= end)
			if (stack->a[j] != stack->capacity - 1)
				break ;
		j--;
	}
	push_cheapest(stack, i, j);
}
