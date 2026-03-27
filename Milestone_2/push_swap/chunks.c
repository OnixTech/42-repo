/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:19:35 by luciano           #+#    #+#             */
/*   Updated: 2026/03/27 12:36:07 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks(t_data *stack)
{
	int ch_size;

	ch_size = chunks_size(stack);
	push_chunk_b(stack, ch_size);
}

int	chunks_size(t_data *stack)
{
	if (stack->size_a < 100)
		return (10);
	else if (stack->size_a < 500)
		return (30);
	else	
		return (50);
}

void	push_chunk_b(t_data *stack, int  ch_size)
{
	int	pushed;

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
	pushed = 0;
	while (stack->size_a > ch_size && pushed < ch_size)
	{
		if (stack->a[0] >= 0 && stack->a[0] < 10)
		{
			pb(stack);
			pushed++;
		}
		else
			ra(stack);
	}
	i = 0;
	while (i < stack->size_b)
		printf("%d ", stack->b[i++]);
	printf("\n");
}
