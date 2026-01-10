/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:05:42 by luciano           #+#    #+#             */
/*   Updated: 2026/01/10 19:17:18 by lupetill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	buff_size(size_t n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n /= 16;
	}
	return (count);
}

int	ft_puthexa(size_t n, char format)
{
	int		size;
	char	*buff;

	if (!n)
		return (ft_putstr_fd("0", 1));
	size = buff_size(n);
	buff = (char *)malloc(sizeof(char) * (size + 1));
	if (!buff)
		return (0);
	buff[size--] = '\0';
	while (size >= 0)
	{
		if (n % 16 > 9)
			buff[size] = (n % 16) - 10 + format - 23;
		else
			buff[size] = (n % 16) + 48;
		n /= 16;
		size--;
	}
	size = ft_putstr_fd(buff, 1);
	free(buff);
	return (size);
}
