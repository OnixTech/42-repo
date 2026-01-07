/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:10:20 by luciano           #+#    #+#             */
/*   Updated: 2026/01/06 15:13:58 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static	int	length(size_t nbr)
{
	int	count;

	count = 1;
	while(nbr > 9)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	size_t	nbr;
	char	*buff;
	int	size;

	nbr = (size_t)ptr;
	size = length(nbr) + 2;
	buff = (char *)malloc(sizeof(char) * (size));
	if (!buff)
		return (0);
	ft_memset(buff, '0', size - 1);
	buff[size--] = '\0';
	while(size > 1)
	{
		if (nbr % 16 > 9)
			buff[size] = (nbr % 16) - 10 + 'a';
		else
			buff[size] = (nbr % 16) + 48;
		nbr /= 16;
		size--;
	}
	buff[size] = 'x';
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
