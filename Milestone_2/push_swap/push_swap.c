/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:10 by luciano           #+#    #+#             */
/*   Updated: 2026/03/12 20:41:02 by luciano          ###   ########.fr       */
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
	while (i < stack->capacity)
		printf("%d\n", stack->a[i++]);
	printf("\n");
	i = 0;
	while (i < stack->capacity)
		printf("%d\n", stack->b[i++]);
	printf("\n");
	pb(stack);
	pb(stack);
	pb(stack);
	pb(stack);
	pb(stack);
	rra(stack);
	printf("size_a -> %i ", stack->size_a);
	printf("size_b -> %i ", stack->size_b);
	printf("capacity -> %i\n", stack->capacity);
	i = 0;
	while (i < stack->capacity)
		printf("%d\n", stack->a[i++]);
	printf("\n");
	i = 0;
	while (i < stack->capacity)
		printf("%d\n", stack->b[i++]);
	printf("size_a -> %i ", stack->size_a);
	printf("size_b -> %i ", stack->size_b);
	printf("capacity -> %i\n", stack->capacity);
	return (1);
}
