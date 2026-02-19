/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:05:42 by luciano           #+#    #+#             */
/*   Updated: 2026/01/10 14:21:48 by lupetill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	ft_putunbr(size_t n, int fd)
{
	long	nbr;
	int		length;

	length = 1;
	nbr = n;
	if (nbr >= 10)
	{
		length += ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
	return (length);
}

int	ft_putu(size_t n)
{
	int	length;

	if (n == 0)
		return (ft_putchar_fd('0', 1));
	return (ft_putunbr(n, 1));
}
