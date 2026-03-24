/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:03:03 by luciano           #+#    #+#             */
/*   Updated: 2026/03/24 12:15:13 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_data *stack)
{
	if (stack->a[0] > stack->a[1])
		sa(stack);
}

void sort_three(t_data *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a[0];
	b = stack->a[1];
	c = stack->a[2];
	if (a < b && b < c)
		return ;
	if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	if (a > b && a > c && c > b)
		ra(stack);
	if (c > a && c > b && a > b)
		sa(stack);
	if (b > a && b > c && c > a)
	{
		rra(stack);
		sa(stack);
	}
	if (b > a && b > c && a > c)
		rra(stack);
}

void sort_four_five(t_data *stack)
{
	int	min;

	min = min_val(stack);
	push_min(stack, min);
	if (stack->size_a == 4)
	{
		min = min_val(stack);
		push_min(stack, min);
	}
		sort_three(stack);
		pa(stack);
	if (stack->size_b)
		pa(stack);
}

int	min_val(t_data *stack)
{
	int	i;
	int	j;
	i = 0;
	while ( i < stack->size_a - 1)
	{
		j = 0;
		while (stack->a[i] <= stack->a[i + j] && i + j < stack->size_a)  
			j++;
		if (i + j == stack->size_a)
			break ;
		i++;
	}
	return (i);
}

void push_min(t_data *stack, int min)
{
	if (min == 1)
		sa(stack);
	if (min == 2)
	{
		ra(stack);
		sa(stack);
	}
	if (min == 3 || min == 4)
		rra(stack);
	if (min == 3 && stack->size_a == 5)
		rra(stack);
	pb(stack);
}
