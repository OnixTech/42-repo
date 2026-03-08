/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:44:10 by luciano           #+#    #+#             */
/*   Updated: 2026/03/08 08:10:25 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *c)
{
	if (*c >= '0')
		if (*c <= '9')
			return (1);
	return (0);
}

int	ft_sign(char *c)
{
	if (*c == '-' || *c == '+')
		return (1);
	return (0);
}
int	ft_digit_sign(char *c)
{
	if (ft_sign(c))
		return (1);
	if (*c >= '0')
		if (*c <= '9')
			return (1);
	return (0);
}
long	ft_atoi(char *str)
{
	long	number;
	int	sign;

	number = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while(*str != ' ' && *str)
		number = (number * 10) + (*str++) - '0';
	number *= sign;
	return (number);
}
