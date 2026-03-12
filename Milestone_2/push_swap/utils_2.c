/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:25:23 by luciano           #+#    #+#             */
/*   Updated: 2026/03/12 14:49:50 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_data *stack)
{
	if (stack->a)
	{
		free(stack->a);
		stack->a = NULL;
	}
	if (stack->b)
	{
		free(stack->b);
		stack->b = NULL;
	}
	write(2, "Error\n", 6);
	return (0);
}

void	init(t_data *stack)
{
	stack->a = NULL;
	stack->size_a = 0;
	stack->b = NULL;
	stack->size_b = 0;
	stack->capacity = 0;
}

int	init_stack(t_data *stack)
{
	stack->b = (int *)malloc(sizeof(int) * stack->capacity);
	if (!stack->b)
		return (0);
	return (1);
}

void	end(t_data *stack)
{
	if (stack->a)
	{
		free(stack->a);
		stack->a = NULL;
	}
	if (stack->b)
	{
		free(stack->b);
		stack->b = NULL;
	}
}
