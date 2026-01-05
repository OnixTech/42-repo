/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:04:19 by lupetill          #+#    #+#             */
/*   Updated: 2026/01/05 20:28:22 by luciano          ###   ########.fr       */
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
		length = ft_putchar((char)va_arg(*args, int), 1);
	else if (c == 's')
	{
		s = va_arg(*args, char *);
		length = ft_putstr(s);
	}
	else if (c == 'p')
		length = ft_putptr((void *)va_arg(*args, size_t));
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	i;
	int	length;
	int	j;

	length = 0;
	i = 0;
	j = 0;
	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			if(type_argument(str[i + 1]))
				length += print(str[i + 1], &args);
			i++;
			j++;
		}
		else
			length += ft_putchar(&str[i], 1);
		i++;
	}
	va_end(args);
	return (length + i - j);
}

#include <stdio.h>
int	main(int arg, char **argc)
{
	char	*p;
	char	a;

	a = 10;
	p = &a;
	(void)arg;
	ft_printf("My function -> Hola %s %c %p hehehe\n", argc[1], 'c', p);
	printf("Original -> Hola %s %c %p hehehe\n", argc[1], 'c', p);
	return (0);
}
