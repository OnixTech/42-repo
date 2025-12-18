/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:41:27 by luciano           #+#    #+#             */
/*   Updated: 2025/12/08 14:10:36 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	len;
	size_t	i;

	if (!s)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, s + i);
		i++;
	}
}
/*
#include <stdio.h>

void	adapter(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}
int	main(void)
{
	char    original[5] = "hola";

	printf("original -> %s\n", original);
	ft_striteri(original, adapter);
	printf("after -> %s\n", original);
	return (0);
}*/
