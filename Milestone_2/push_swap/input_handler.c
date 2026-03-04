/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:03:02 by luciano           #+#    #+#             */
/*   Updated: 2026/03/04 13:41:40 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_input(int arg, char **argc)
{
	if (arg == 2)
		return (parse_string(argc[1]));
	else if (arg > 2)
		return (parse_args(arg, argc[arg - 1]));
	else
		return (NULL);
}
int	*parse_string(char *argc)
{
	size_t	i;
	int	size;
	int *p;

	size = 0;
	i = 0;
	p = (int *)malloc(sizeof(int) * 1);
	if (!p)
		return (NULL);
	while(argc[i])
		if (ft_isdigit(&argc[i++]))
			size++;
	*p = size;
	return (p);
}
int	*parse_args(int arg, char *argc)
{
	int *p;

	p = NULL;
	(void)arg;
	printf("parse args %s\n", argc);
	return (p);
}
