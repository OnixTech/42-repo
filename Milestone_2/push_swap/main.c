/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:07 by luciano           #+#    #+#             */
/*   Updated: 2026/03/04 13:35:21 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arg, char **argc)
{
	int	*input;

	input = parse_input(arg, argc);
	if (!input)
		write(1, "Error\n", 6);
	else
		push_swap(input);
	free(input);
	return (0);
}
