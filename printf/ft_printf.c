/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:04:19 by lupetill          #+#    #+#             */
/*   Updated: 2026/01/04 20:50:47 by luciano          ###   ########.fr       */
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

static	void	print(const char c, va_list *args)
{
	char	*s;

	if (c == 'c')
		ft_putchar_fd((char)va_arg(*args, int), 1);
	if (c == 's')
	{
		s = va_arg(*args, char *);	
		write(1, s, ft_strlen(s));
	}
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	i;

	i = 0;
	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			if(type_argument(str[i + 1]))
				print(str[i + 1], &args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (0);
}

#include <stdio.h>
int	main(int arg, char **argc)
{
	(void)arg;
	ft_printf("My function -> Hola %s %c\n", argc[1], 'c');
	printf("Original -> Hola %s %c\n", argc[1], 'c');
	return (0);
}
