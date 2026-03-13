/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:10 by luciano           #+#    #+#             */
/*   Updated: 2026/03/13 15:23:12 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_data *stack)
{
	int	i;

	printf("size_a -> %i ", stack->size_a);
	printf("size_b -> %i ", stack->size_b);
	printf("capacity -> %i\n", stack->capacity);
	i = 0;
	while (i < stack->size_a)
		printf("%d\n", stack->a[i++]);
	printf("\n");
	i = 0;
	while (i < stack->size_b)
		printf("%d\n", stack->b[i++]);
	pb(stack);
	pb(stack);
	pb(stack);
	rrr(stack);
	printf("\n");
	printf("size_a -> %i ", stack->size_a);
	printf("size_b -> %i ", stack->size_b);
	printf("capacity -> %i\n", stack->capacity);
	i = 0;
	while (i < stack->size_a)
		printf("%d\n", stack->a[i++]);
	printf("\n");
	i = 0;
	while (i < stack->size_b)
		printf("%d\n", stack->b[i++]);
	printf("size_a -> %i ", stack->size_a);
	printf("size_b -> %i ", stack->size_b);
	printf("capacity -> %i\n", stack->capacity);
	return (1);
}
