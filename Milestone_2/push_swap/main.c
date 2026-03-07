/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:07 by luciano           #+#    #+#             */
/*   Updated: 2026/03/07 11:02:44 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arg, char **argc)
{
	int	*input;
	int size;

	size = 0;
	input = NULL;
	if (!parse_input(arg, argc, &size, &input))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	push_swap(input, size);
	free(input);
	return (0);
}
