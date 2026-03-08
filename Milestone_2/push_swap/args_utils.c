/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 09:02:56 by luciano           #+#    #+#             */
/*   Updated: 2026/03/08 09:51:38 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int args_validation(int arg, char **argc, int **size)
{
	int i;

	i = 1;
	while (i < arg)
		if (!string_validation(argc[i++], size))
			return (0);
	return (1);
}
