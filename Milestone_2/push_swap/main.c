/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:07 by luciano           #+#    #+#             */
/*   Updated: 2026/02/24 21:58:39 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arg, char **argc)
{
	//int	*input;

	if (error_handle(argc))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	/*if (arg > 2)
		input = input_handle(&argc);
	else if (arg == 2)
		input_handle(argc)*/
	(void)arg;
	printf("Hello push_swap");
	return (0);
}
