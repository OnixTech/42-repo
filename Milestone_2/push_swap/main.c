/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:07 by luciano           #+#    #+#             */
/*   Updated: 2026/04/13 13:07:05 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arg, char **argc)
{
	t_data	stack;

	init(&stack);
	if (arg > 1)
	{
		if (!parse_input(arg, argc, &stack))
			return (error(&stack));
		if (!init_stack(&stack))
			return (error(&stack));
		sort(&stack);
	}
	end(&stack);
	return (0);
}
