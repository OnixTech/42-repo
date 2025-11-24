/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:42:39 by lupetill          #+#    #+#             */
/*   Updated: 2025/11/24 09:43:45 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	*c;
	int	a, i;
	
	c = "abcdefghijklmnopqrstuvwxyz";
	i = 0;
	printf("#_ FUNTION isalpha:\n\tinputs -> 'a' 'b' 'c'...'z'\n");
	while(c[i++])
	{
		if (ft_isalpha(c[i]))
			i++;
		else
		{
			printf("FAIL IN -> %c\n", c[i]);
			break;
		}
		if (!c[i])
			printf("--PASS--\n");
        }
	c = "0 0123456789´?*#!&%712";
	i = 0;
	printf("\tinputs -> 0123456789´?*#!&712\n");
	while(c[i++])
	{
		if (!c[i])
		{
			printf("--PASS--\n");
			break;
		}
		if (!ft_isalpha(c[i]))
			i++;
		else
		{
			printf("FAIL IN -> %c\n", c[i]);
			break;
		}
        }
/*
	if (ft_isdigit(c))
                printf("ft_ isalpha -> %s = is digit\n", c);
	c = "1";
	a = *c;
	if (ft_isalnum(a))
                printf("ft_ isalnum -> %s = is alphanumeric\n", c);	
	c = "a";	
	a = *c;
	if (ft_isalnum(a))
                printf("ft_ isalnum -> %s = is alphanumeric\n", c);
*/	return (0);
}

