/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:25:23 by luciano           #+#    #+#             */
/*   Updated: 2026/03/11 22:33:58 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int **stack_a, int **stack_b)
{
	if (stack_a && *stack_a)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	if (stack_b && *stack_b)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	write(2, "Error\n", 6);
	return (0);
}

void	init(int **stack_a, int *size_a, int **stack_b, int *size_b)
{
	*size_a = 0;
	*stack_a = NULL;
	*size_b = 0;
	*stack_b = NULL;
}

int	init_stack_b(int size_a, int **stack_b, int *size_b)
{
	*size_b = size_a;
	*stack_b = (int *)malloc(sizeof(int) * *size_b);
	if (!*stack_b)
		return (0);
	return (1);
}
void	end(int **stack_a, int **stack_b)
{
	if (stack_a && *stack_a)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	if (stack_b && *stack_b)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
}
