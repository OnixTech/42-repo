/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 23:06:25 by luciano           #+#    #+#             */
/*   Updated: 2026/04/03 23:06:41 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	get_scheme(t_data *stack, int	**scheme)
{
        int     i;
        int     j;
        int     tmp;

        *scheme = (int *)malloc(sizeof(int) * stack->capacity);
        if (!*scheme)
                return ;
        i = -1;
        while (++i < stack->capacity)
                (*scheme)[i] = i;
	i = 0;
        while (i < stack->capacity - 1)
        {
                j = i + 1;
                while (j < stack->capacity)
                {
                        if (stack->a[(*scheme)[i]] > stack->a[(*scheme)[j]])
                        {
                                tmp = (*scheme)[i];
                                (*scheme)[i] = (*scheme)[j];
                                (*scheme)[j] = tmp;
                        }
			j++;
                }
                i++;
        }
}

void stack_indexed(t_data *stack)
{
	int	i;
	int	*scheme;
	int	*idx;

	get_scheme(stack, &scheme);
	if (!scheme)
		return ;
	idx = malloc(sizeof(int) * stack->capacity);
	if (!idx)
	{
		free(scheme);
		return ;
	}
	i = -1;
	while (++i < stack->capacity)
		idx[scheme[i]] = i;
	i = -i;
	while (++i < stack->capacity)
		stack->a[i] = idx[i];
	free(scheme);
	free(idx);
}

