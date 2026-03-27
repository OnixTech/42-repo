/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:10 by luciano           #+#    #+#             */
/*   Updated: 2026/03/25 17:38:45 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *stack)
{
	int	i;

	while (!is_sorted(stack))
	{
		if (stack->size_a == 2)
			sort_two(stack);
		else if (stack->size_a == 3)
			sort_three(stack);
		else if (stack->size_a <= 5)
			sort_four_five(stack);
		else
		{
			chunks(stack);
			return ;
		}
	}
	i = 0;
	while (i < stack->size_a)
		printf("%d ", stack->a[i++]);
	printf("\n");
}

int	is_sorted(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

