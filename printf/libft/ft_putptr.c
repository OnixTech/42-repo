/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:10:20 by luciano           #+#    #+#             */
/*   Updated: 2026/01/10 18:55:06 by lupetill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static	int	length(size_t nbr)
{
	size_t	count;

	count = 0;
	while (nbr)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	char	*buff;
	int		size;
	size_t	nbr;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	nbr = (size_t)ptr;
	size = length(nbr) + 2;
	buff = (char *)malloc(sizeof(char) * (size + 1));
	if (!buff)
		return (0);
	buff[size--] = '\0';
	while (size > 1)
	{
		if (nbr % 16 > 9)
			buff[size--] = (nbr % 16) - 10 + 'a';
		else
			buff[size--] = (nbr % 16) + '0';
		nbr /= 16;
	}
	buff[size--] = 'x';
	buff[size] = '0';
	size = ft_putstr_fd(buff, 1);
	free(buff);
	return (size);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*p;
	int	a;

	p = &a;
	printf(" - %d - ", printf("%p", p));
	printf("\n");
	printf(" - %d - ", ft_putptr(p));
	return (0);
}
*/
