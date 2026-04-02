/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:19:35 by luciano           #+#    #+#             */
/*   Updated: 2026/03/31 14:50:18 by luciano          ###   ########.fr       */
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
	int	start;
	int	end;

	int i;
	int j;
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
	while (stack->size_a > ch_size && pushed < ch_size / 2)
	{
		i = 0;
		while (i <= stack->size_a / 2)
		{
			if (stack->a[i] >= start && stack->a[i] <= end / 2)
				break ;
			i++;
		}
		j = 0;
		while (j < stack->size_a / 2)
		{
			if (stack->a[stack->size_a - j - 1] >= start && stack->a[stack->size_a - j - 1] <= end / 2)
				break ;
			j++;
		}
		if (i <= (j + 1))
		{
			while (i)
			{
				ra(stack);
				i--;
			}
			pb(stack);
			if (stack->size_b > 1 && stack->b[0] < stack->b[1])
				sb(stack);
			pushed++;
		}
		else
		{
			j++;
			while (j--)
			{
				rra(stack);
			}
			pb(stack);
			if (stack->size_b > 1 && stack->b[0] < stack->b[1])
				sb(stack);
			pushed++;
		}
	}
	printf("\nstack b : ");
	i = 0;
	while (i < stack->size_b)
		printf("%d ", stack->b[i++]);
	printf("\n");
}
