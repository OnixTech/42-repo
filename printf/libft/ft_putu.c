/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:05:42 by luciano           #+#    #+#             */
/*   Updated: 2026/01/07 13:49:19 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
 
int     ft_putunbr(unsigned int n, int fd)
{
        long    nbr;
        int     length;

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

int	ft_putu(unsigned int n)
{
	int	length;

	if (n == 0)
		return (ft_putchar_fd('0', 1));
	return (ft_putunbr(n, 1));
}
