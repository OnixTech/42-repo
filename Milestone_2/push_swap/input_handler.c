/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:03:02 by luciano           #+#    #+#             */
/*   Updated: 2026/03/08 08:05:06 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int arg, char **argc, int *size, int **input)
{
	if (arg == 2)
		return (parse_string(argc[1], size, input));
	else if (arg > 2)
		return (parse_args(arg, argc[arg - 1]));
	else
		return (0);
}
int	parse_string(char *str, int *size, int **input)
{
	if (!string_validation(str, &size))
		return (0);
	*input = (int *)malloc(sizeof(int) * *size);
	if (!input)
		return (0);
	if (!intjoin(str, *size, input))
		return (0);
	return (1);
}
int	parse_args(int arg, char *argc)
{
	(void)arg;
	printf("parse args %s\n", argc);
	return (0);
}
int	string_validation(char *str, int **size)
{
	int	flag;

	flag = 0;
	if (!ft_digit_sign(str))
		return (0);
	while(*str)
	{
		if (*str == ' ' && !ft_digit_sign(str + 1))
			return (0);
		if (ft_sign(str) && !ft_isdigit(str + 1))
			return (0);
		if (ft_isdigit(str++))
		{
			if (flag == 0)
				**size += 1;
			flag = 1;
		}
		else
			flag = 0;
	}
	return (1);
}
int intjoin(char *str, int size, int **input)
{
	int	i;
	long	number;

	i = 0;
	while (i < size)
	{
		number = ft_atoi(str);
		if (number > 2147483647 || number < -2147483648)
			return (0);
		(*input)[i++] = number;
		while (*str != ' ')
			str++;
		str++;
	}
	return (1);
}
