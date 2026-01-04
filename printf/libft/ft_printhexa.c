/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:10:20 by luciano           #+#    #+#             */
/*   Updated: 2026/01/04 23:45:32 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include <stdio.h>

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

void	ft_printhexa(void *ptr)
{
	size_t	nbr;
	char	*buff;
	int	size;

	nbr = (size_t)ptr;
	size = length(nbr);
	buff = (char *)malloc(sizeof(char) * (size + 1));
	if (!buff)
		return ;
	buff[size--] = '\0';
	while(nbr)
	{
		
		if (nbr % 16 > 9)
			buff[size] = (nbr % 16) - 10 + 'a';
		else
		{
			buff[size] = (nbr % 16) + 48;
		}
		//printf("%zx\n", nbr);
		size--;
		nbr /= 16;
	}
	write(1, buff, ft_strlen(buff));
	free(buff);
}

int	main(void)
{
	int	*p;
	int	a;

	p = &a;
	printf("%p\n", p);
	ft_printhexa(p);
	return (0);
}
