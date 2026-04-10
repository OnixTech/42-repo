/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:45:34 by luciano           #+#    #+#             */
/*   Updated: 2026/04/10 18:34:32 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     chunk_size(t_data *stack)                                              
{
        if (stack->size_a < 100)
                return (10);
        else if (stack->size_a < 500)
                return (30);
        else    
                return (50);
}

void index_positions(t_data *stack, int start, int end, int *i, int *j)
{
	*i = 0;
	while (*i <= stack->size_a / 2)
	{
		if (stack->a[*i] >= start && stack->a[*i] <= end)
			if (stack->a[*i] != stack->capacity - 1)
				break ;
		(*i)++;
	}
	*j = stack->size_a - 1;
	while (*j > stack->size_a / 2)
	{
		if (stack->a[*j] >= start && stack->a[*j] <= end)
			if (stack->a[*j] != stack->capacity - 1)
				break ;
		(*j)--;
	}
}

void push_cheapest(t_data *stack, int i, int j)
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
