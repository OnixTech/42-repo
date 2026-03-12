/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:10 by luciano           #+#    #+#             */
/*   Updated: 2026/03/12 14:41:02 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->capacity)
		printf("%d\n", stack->a[i++]);
	printf("\n");
	i = 0;
	while (i < stack->capacity)
		printf("%d\n", stack->b[i++]);
	return (1);
}
