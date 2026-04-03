/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:19:35 by luciano           #+#    #+#             */
/*   Updated: 2026/04/04 00:20:33 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks(t_data *stack)
{
	int ch_size;

	ch_size = chunk_size(stack);
	push_chunk_b(stack, ch_size);
}

void	push_chunk_b(t_data *stack, int  ch_size)
{
	int	pushed;
	int	start;
	int	end;

	int i;
	i = 0;
	while (i < stack->size_a)
		printf("%d ", stack->a[i++]);
	printf("\n");
	stack_indexed(stack);
	i = 0;
	while (i < stack->size_a)
		printf("%d ", stack->a[i++]);
	printf("\n");
	i = 0;
	while (i < stack->size_b)
		printf("%d ", stack->b[i++]);
	printf("\n");
	i = 0;
	start = 0;
	end = ch_size - 1;
	pushed = 0;
	while (stack->size_a > ch_size && pushed < ch_size)
	{
		chunk_bottom(stack, start, end, &pushed);
		chunk_top(stack, start, end, &pushed);
	}
	printf("\nstack b : ");
	i = 0;
	while (i < stack->size_b)
		printf("%d ", stack->b[i++]);
	printf("\n");
}

void	chunk_bottom(t_data *stack, int start, int end, int *pushed)
{
	int	half_bottom;
	int	i;
	int	j;

	half_bottom = ((end - start) / 2) + start;
	index_positions(stack, start, half_bottom, &i, &j);
	push_cheapest(stack, i, j, pushed);
}

void	chunk_top(t_data *stack, int start, int end, int *pushed)
{
	int	half_top;
	int	i;
	int	j;

	half_top = ((end - start) / 2) + start + 1;
	index_positions(stack, half_top, end, &i, &j);
	push_cheapest(stack, i, j, pushed);
}
