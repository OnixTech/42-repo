/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:03:02 by luciano           #+#    #+#             */
/*   Updated: 2026/03/11 21:17:54 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int arg, char **argc, int *size, int **input)
{
	if (arg == 2)
		return (parse_string(argc[1], size, input));
	else if (arg > 2)
		return (parse_args(arg, argc, size, input));
	else
		return (0);
}

int	parse_string(char *str, int *size, int **input)
{
	if (!string_validation(str, size))
		return (0);
	*input = (int *)malloc(sizeof(int) * *size);
	if (!*input)
		return (0);
	if (!str_intjoin(str, *size, input))
	{
		free(*input);
		*input = NULL;
		return (0);
	}
	return (1);
}

int	parse_args(int arg, char **str, int *size, int **input)
{
	if (!args_validation(arg, str, size))
		return (0);
	*input = (int *)malloc(sizeof(int) * *size);
	if (!*input)
		return (0);
	if (!args_intjoin(str, *size, input))
	{
		free(*input);
		*input = NULL;
		return (0);
	}
	return (1);
}
