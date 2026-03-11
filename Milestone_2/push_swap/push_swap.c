/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:10 by luciano           #+#    #+#             */
/*   Updated: 2026/03/11 22:29:51 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(int **stack_a, int *size_a, int **stack_b, int *size_b)
{
	int	i;

	i = 0;
	while (i < *size_a)
		printf("%d\n", (*stack_a)[i++]);
	printf("\n");
	i = 0;
	while (i < *size_b)
		printf("%d\n", (*stack_b)[i++]);
	return (1);
}
