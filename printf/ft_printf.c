/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:04:19 by lupetill          #+#    #+#             */
/*   Updated: 2025/12/29 14:39:07 by lupetill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	int	isargument(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x'
				|| c == 'X' || c == '%')
		return (1);
	return (0);
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
			if(isargument(str[i + 1]))
				printf("%s", va_arg(args, char*));
		//		write(1, &str[i], 1);
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
	ft_printf("Hola %s%s", argc[1], argc[2]);
	return (0);
}
