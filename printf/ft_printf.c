/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:04:19 by lupetill          #+#    #+#             */
/*   Updated: 2025/12/29 16:09:39 by lupetill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	int	type_argument(const char c)
{
	if (c == 'c' || c == 's' || c == 'p'|| c == 'd'
		||c == 'i' || c == 'u' || c == 'x' 
			|| c == 'X' || c == '%')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static	void	print(const char c, void *arg)
{
	if (c == 'c')
		write(1, (char *)arg, 1);
	if (c == 's')
		write(1, (char *)arg, ft_strlen((char *)arg));
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
				print(str[i + 1], va_arg(args, char*));		
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

int	main(int arg, char **argc)
{
	(void)arg;
	ft_printf("Hola %c%s", argc[1], argc[2]);
	return (0);
}
