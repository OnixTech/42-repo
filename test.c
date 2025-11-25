/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:42:39 by lupetill          #+#    #+#             */
/*   Updated: 2025/11/25 21:06:23 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

void	test_alpha(void);
void	test_digit(void);
void	test_alnum(void);
void	test_isascii(void);
void	test_isprint(void);
void	test_strlen(void);
void	test_memset(void);

int	main(void)
{
	test_alpha();
	test_digit();
	test_alnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	return (0);
}

void test_alpha(void)
{
	char	*c;
	int	i;
	
	i = 0;
	c = "abcdefghijklmnopqrstuvwxyz";
	printf("#_ FUNTION isalpha:\n\tinputs -> 'a' 'b' 'c'...'z'\n");
	while(c[i++])
	{
		if (ft_isalpha(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break;
		}
		if (!c[i])
			printf("\t--PASS--\n");        
	}
	i = 0;
	c = "0 0123456789´?*#!&%712";
	printf("\tinputs -> 0123456789´?*#!&712\n");
	while(c[i++])
	{
		if (!c[i])
		{
			printf("\t--PASS--\n");
			break;
		}
		if (!ft_isalpha(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break;
		}
       	}
}

void test_digit(void)
{
	char	*c;
	int	i;
	
	i = 0;
	c = "0123456789";
	printf("#_ FUNTION isdigit:\n\tinputs -> '1' '2' '3'...'0'\n");
	while(c[i++])
	{
		if (ft_isdigit(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break;
		}
		if (!c[i])
			printf("\t--PASS--\n");        
	}
	i = 0;
	c = "abcdefghijklmnopqtuvwxyz´?*#!&";
	printf("\tinputs -> abcdefghijklmnopqtuvwxyz´?*#!&\n");
	while(c[i++])
	{
		if (!c[i])
		{
			printf("\t--PASS--\n");
			break;
		}
		if (!ft_isdigit(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break;
		}
       	}
}

void test_alnum(void)
{
	char	*c;
	int	i;
	
	i = 0;
	c = "01d2b34a56cz789";
	printf("#_ FUNTION isalnum:\n\tinputs -> 01d2b34a56cz789\n");
	while(c[i])
	{
		if (ft_isalnum(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break;
		}
		if (!c[i])
			printf("\t--PASS--\n");        
	}
	i = 0;
	c = "();,.§´?*#!&";
	printf("\tinputs -> ();,.§´?*#!&\n");
	while(c[i])
	{
		if (!ft_isalnum(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break;
		}
		if (!c[i])
		{
			printf("\t--PASS--\n");
			break;
		}
       	}
}

void	test_isascii(void)
{	
	int	c[128];
	int	i;
	
	i = -1;
	while(i++ < 127)
		c[i] = i;
	printf("#_ FUNTION isascii:\n\tinputs -> '0' '1' '2'...'127'\n");
	i = 0;
	while(i < 128)
	{
		if (ft_isascii(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %d\n", c[i]);
			break;
		}
		if (i == 128)
			printf("\t--PASS--\n");
	}
	printf("\tinput -> '-1' '128'\n");
	if (!ft_isascii(-1))
		if(!ft_isascii(128))
			printf("\t--PASS--\n");
}

void	test_isprint(void)
{	
	int	c[97];
	int	i;
	
	i = 31;
	while(i++ < 127)
		c[i - 32] = i;
	printf("#_ FUNTION isprint:\n\tinputs -> '32' '33' '34'...'126'\n");
	i = 32;
	while(i < 127)
	{
		if (ft_isprint(c[i - 32]))
			i++;
		else
		{
			printf("\tFAIL IN -> %d\n", c[i - 32]);
			break;
		}
		if (i == 127)
			printf("\t--PASS--\n");
	}
	printf("\tinput -> '31' '127'\n");
	if (!ft_isprint(31))
	{
		if(!ft_isprint(127))
			printf("\t--PASS--\n");
	}
	else
	{
			printf("\tFAIL IN -> %d\n", c[i - 32]);
	}
}

void	test_strlen(void)
{
	char	*str;
	
	str = "Hola que tal";
	printf("#_ FUNTION strlen:\n\tinput -> Hola que tal\n");
	if (strlen(str) == ft_strlen(str))
			printf("\t--PASS--\n");
	else
	{
			printf("\t**FAIL**\n");
			printf("\tstrlen ->    %lu\n", strlen(str));
			printf("\tft_strlen -> %zu\n", ft_strlen(str));
	}
	str = "";
	printf("\tinputs -> '' (empty string)\n");
	if (strlen(str) == ft_strlen(str))
			printf("\t--PASS--\n");
	else
	{
			printf("\t**FAIL**\n");
			printf("\tstrlen ->    %lu\n", strlen(str));
			printf("\tft_strlen -> %zu\n", ft_strlen(str));
	}	
}

void	test_memset(void)
{
	int	n;
	int	arr1[10];
	int	arr2[10];
	int	i;	

	n = 10;
	printf("#_ FUNTION memset:\n\tinput -> arr[10], 0xA, sizeof(arr)\n");
	i = -1;
	while(++i < n)
	{
		arr1[i] = 0x00;
		arr2[i] = 0x01;	
	}
	memset(arr1, 0x0A, sizeof(arr1));
	ft_memset(arr2, 0x0A, sizeof(arr2));
	if (memcmp(arr1, arr2, sizeof(arr1)) == 0)
			printf("\t--PASS--\n");
	else
	{
			printf("\t**FAIL**\n");
			i = 0;
			while(i < n)
				printf("%x", arr1[i++]);
			printf("\n");
			i = 0;
			while(i < n)
				printf("%x", arr2[i++]);
	}
}
