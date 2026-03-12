/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:03:02 by luciano           #+#    #+#             */
/*   Updated: 2026/03/12 14:42:11 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int arg, char **argc, t_data *stack)
{
	if (arg == 2)
		return (parse_string(argc[1], stack));
	else if (arg > 2)
		return (parse_args(arg, argc, stack));
	else
		return (0);
}

int	parse_string(char *str, t_data *stack)
{
	if (!string_validation(str, stack))
		return (0);
	stack->a = (int *)malloc(sizeof(int) * stack->capacity);
	if (!stack->a)
		return (0);
	if (!str_intjoin(str, stack))
	{
		free(stack->a);
		stack->a = NULL;
		return (0);
	}
	return (1);
}

int	parse_args(int arg, char **str, t_data *stack)
{
	if (!args_validation(arg, str, stack))
		return (0);
	stack->a = (int *)malloc(sizeof(int) * stack->capacity);
	if (!stack->a)
		return (0);
	if (!arg_intjoin(str, stack))
	{
		free(stack->a);
		stack->a = NULL;
		return (0);
	}
	return (1);
}
