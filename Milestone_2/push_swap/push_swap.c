/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:10 by luciano           #+#    #+#             */
/*   Updated: 2026/03/24 12:18:04 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_data *stack)
{
	int	i;

	sort_four_five(stack);
	if (is_sort(stack))
	{
		write(1, "OK\n", 3);
		index_scheme(stack);
	}
	else
	{
		write(1, "KO\n", 3);
		index_scheme(stack);
	}
	i = 0;
	printf("\n");
	while (i < stack->size_a)
		printf("%d ", stack->a[i++]);
	printf("\n");
	return (1);
}

int	is_sort(t_data *stack)
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

int	index_scheme(t_data *stack)
{
	int	i;
	int	j;
	int	tmp;
	int	*scheme;

	scheme = (int *)malloc(sizeof(int) * stack->capacity);
	if (!scheme)
		return (0);
	i = 0;
	while (i < stack->capacity)
	{
		scheme[i] = i;
		i++;
	}
	i = 0;
	while (i < stack->capacity - 1)
	{
		j = i + 1;
		while (j < stack->capacity)
		{
			if (stack->a[scheme[i]] > stack->a[scheme[j]])
			{
				tmp = scheme[i];
				scheme[i] = scheme[j];
				scheme[j] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < stack->capacity)
		printf("%d ", scheme[i++]);
	printf("\n");
	return (1);
}
