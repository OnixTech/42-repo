/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:07 by luciano           #+#    #+#             */
/*   Updated: 2026/03/11 22:20:29 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arg, char **argc)
{
	int	*stack_a;
	int *stack_b;
	int size_a;
	int size_b;

	init(&stack_a, &size_a, &stack_b, &size_b);
	if (!parse_input(arg, argc, &size_a, &stack_a))
		return (error(&stack_a, &stack_b));
	if (!init_stack_b(size_a, &stack_b, &size_b))
		return (error(&stack_a, &stack_b));
	if (!sort(&stack_a, &size_a, &stack_b, &size_b))
		return (error(&stack_a, &stack_b));
	end(&stack_a, &stack_b);
	return (0);
}
