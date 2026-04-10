/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:10 by luciano           #+#    #+#             */
/*   Updated: 2026/04/10 19:59:19 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *stack)
{
	int	j;

	stack_indexed(stack);
	while (!is_sorted(stack))
	{
		if (stack->size_a == 2)
			sort_two(stack);
		else if (stack->size_a == 3)
			sort_three(stack);
		else if (stack->size_a <= 5)
			sort_four_five(stack);
		else
			chunks(stack);
	}
	stack_a_cleaner(stack);
//	stack_a(stack);
//	stack_b(stack);
	while (stack->size_b)
	{
		j = 0;
		while (j < stack->size_b)
		{
			if (stack->b[j] == stack->a[0] - 1)
				break ;
			j++;
		}
		if (j < stack->size_b / 2)
		{
			while (j--)
				rb(stack);
			pa(stack);
		}
		else
		{
			j = stack->size_b - j;
			while (j--)
				rrb(stack);
			pa(stack);
		}
	}
	//stack_a(stack);
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

void stack_a(t_data *stack)
{
	int	i;

	i = 0;
	printf("stack a: ");
	while (i < stack->size_a)
		printf ("%d ", stack->a[i++]);
	printf("\n");
}

void stack_b(t_data *stack)
{
        int     i;

        i = 0;
        printf("stack b: ");
        while (i < stack->size_b)
                printf ("%d ", stack->b[i++]);
        printf("\n");
}
