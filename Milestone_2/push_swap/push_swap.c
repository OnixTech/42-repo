/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:10 by luciano           #+#    #+#             */
/*   Updated: 2026/04/11 17:19:45 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *stack)
{
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
	push_back_to_a(stack);
	if (stack->a[0] == stack->capacity - 1)
		ra(stack);
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

void	push_back_to_a(t_data *stack)
{
	int	j;

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
}

void	stack_a_cleaner(t_data *stack)
{
	int	i;
	int	j;

	j = stack->size_a;
	i = 0;
	while (stack->size_b && i < j)
	{
		if (stack->a[0] != stack->capacity - 1)
			pb(stack);
		i++;
	}
}

void	stack_indexed(t_data *stack)
{
	int	i;
	int	*scheme;
	int	*idx;

	scheme = get_scheme(stack);
	if (!scheme)
		return ;
	idx = malloc(sizeof(int) * stack->capacity);
	if (!idx)
	{
		free(scheme);
		return ;
	}
	i = 0;
	while (i < stack->capacity)
	{
		idx[scheme[i]] = i;
		i++;
	}
	indexer_machine(stack, idx);
	free(scheme);
	free(idx);
}
