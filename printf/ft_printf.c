/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:04:19 by lupetill          #+#    #+#             */
/*   Updated: 2026/01/07 13:19:10 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static	int	type_argument(const char c)
{
	if (c == 'c' || c == 's' || c == 'p'|| c == 'd'
		||c == 'i' || c == 'u' || c == 'x' 
			|| c == 'X' || c == '%')
		return (1);
	return (0);
}

static	int	print(const char c, va_list *args)
{
	char	*s;
	int	length;

	length = 0;
	if (c == 'c')
		length = ft_putchar_fd((char)va_arg(*args, int), 1);
	if (c == 's')
	{
		s = va_arg(*args, char *);
		length = ft_putstr_fd(s, 1);
	}
	if (c == 'p')
		length = ft_putptr((void *)va_arg(*args, size_t));
	if (c == 'd' || c == 'i')
		length = ft_putnbr_fd(va_arg(*args, int), 1);
	if (c == 'u')
		length = ft_putu(va_arg(*args, unsigned int));
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	i;
	int	length;

	length = 0;
	i = 0;
	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			if(type_argument(str[i + 1]))
				length += print(str[i + 1], &args);
			i++;
		}
		else
			length += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (length);
}

#include <stdio.h>
int	main(int arg, char **argc)
{
	unsigned int	*p;
	unsigned int	a;
	int		b;

	b = -2;
	p = &a;
	(void)arg;
	printf(" - %d -\n", ft_printf("Hola, %s %c %p %p %d %i %u hehehe", argc[1], 'c', p, &a, -102, -12, -2));
	printf(" - %d -\n",    printf("Hola, %s %c %p %p %d %i %u hehehe", argc[1], 'c', p, &a, -102, -12, -2));

	return (0);
}
