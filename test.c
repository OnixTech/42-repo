/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:42:39 by lupetill          #+#    #+#             */
/*   Updated: 2025/11/26 15:59:44 by lupetill         ###   ########.fr       */
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
void	test_bzero(void);
void	test_memcpy(void);
void	test_memmove(void);

int	main(void)
{
	test_alpha();
	test_digit();
	test_alnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	return (0);
}

void test_alpha(void)
{
	char	*c;
	int	i;
	
	i = 0;
	c = "abcdefghijklmnopqrstuvwxyz";
	printf("#_ FUNTION isalpha:\n\t*_inputs -> 'a' 'b' 'c'...'z'\n");
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
	printf("\t*_inputs -> 0123456789´?*#!&712\n");
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
	printf("#_ FUNTION isdigit:\n\t*_inputs -> '1' '2' '3'...'0'\n");
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
	printf("\t*_inputs -> abcdefghijklmnopqtuvwxyz´?*#!&\n");
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
	printf("#_ FUNTION isalnum:\n\t*_inputs -> 01d2b34a56cz789\n");
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
	printf("\t*_inputs -> ();,.§´?*#!&\n");
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
	printf("#_ FUNTION isascii:\n\t*_inputs -> '0' '1' '2'...'127'\n");
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
	printf("\t*_input -> '-1' '128'\n");
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
	printf("#_ FUNTION isprint:\n\t*_inputs -> '32' '33' '34'...'126'\n");
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
	printf("\t*_input -> '31' '127'\n");
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
	printf("#_ FUNTION strlen:\n\t*_input -> Hola que tal\n");
	if (strlen(str) == ft_strlen(str))
			printf("\t--PASS--\n");
	else
	{
			printf("\t**FAIL**\n");
			printf("\tstrlen ->    %lu\n", strlen(str));
			printf("\tft_strlen -> %zu\n", ft_strlen(str));
	}
	str = "";
	printf("\t*_inputs -> '' (empty string)\n");
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
	printf("#_ FUNTION memset:\n\t*_input -> arr[10], 0xA, sizeof(arr)\n");
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

void	test_bzero(void)
{
	int	n;
	int	arr1[10];
	int	arr2[10];
	int	i;	

	n = 10;
	printf("#_ FUNTION bzero:\n\t*_input -> arr[10], sizeof(arr)\n");
	i = -1;
	while(++i < n)
	{
		arr1[i] = 0xff;
		arr2[i] = 0xff;	
	}
	bzero(arr1, sizeof(arr1));
	ft_bzero(arr2, sizeof(arr2));
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
	bzero(arr1, (0));
	ft_bzero(arr2, (0));
	printf("\t*_input -> arr[10], 0\n");
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

void	test_memcpy(void)
{
	unsigned char	src[10];
	unsigned char	dst1[10];
	unsigned char	dst2[10];
	int	i;	

	printf("#_ FUNTION memcpy:\n\t*_input -> dst[10], src = 0 1 2...9, sizeof(dst)\n");
	i = 0;
	while(i < 10)
	{
		dst1[i] = 0xff;
		dst2[i] = 0xff;
		src[i] = 0 + i;
		i++;	
	}
	if (memcmp((char *)memcpy(dst1, src, sizeof(dst1)), (char *)ft_memcpy(dst2, src, sizeof(dst2)), sizeof(dst1)) == 0)
	{
			printf("\t--PASS--\n");
			i = 0;
			printf("\tmemcpy ->    ");
			while(i < 10)
				printf("%x", dst1[i++]);
			printf("\n");
			printf("\tft_memcpy -> ");
			i = 0;
			while(i < 10)
				printf("%x", dst2[i++]);
			printf("\n");
	}
	else
	{
			printf("\t**FAIL**\n");
			i = 0;
			while(i < 10)
				printf("%c", dst1[i++]);
			printf("\n");
			i = 0;
			while(i < 10)
				printf("%c", dst2[i++]);
	}
}

void	test_memmove(void)
{
	unsigned char	src[10];
	unsigned char	dst1[10];
	unsigned char	dst2[10];
	unsigned char	*d1;
	unsigned char	*d2;
	int	i;	

	printf("#_ FUNTION memmove:\n\t*_input -> dst = KLMNOPQRST, src = ABCDEFGHIJ, 10\n");
	i = 0;
	while(i < 10)
	{
		src[i] = 'A' + i;
		dst1[i]= 'K' + i;
		dst2[i]= 'K' + i;
		i++;
	}
	i = 0;
	printf("\tBefore call memmove:\n");
	printf("\tmemmove ->    src -> ");
	while(i < 10)
		printf("%c", src[i++]);
	i = 0;
	printf(" dst -> ");
	while(i < 10)
		printf("%c", dst1[i++]);
	printf("\n");
	printf("\tft_memmove -> src -> ");
	i = 0;
	while(i < 10)
		printf("%c", src[i++]);
	i = 0;
	printf("\tdst -> ");
	while(i < 10)
		printf("%c", dst2[i++]);
	printf("\n");
	if (memcmp((char *)memmove(dst1, src, 10), (char *)ft_memmove(dst2, src, 10), 10) == 0)
	{
			printf("\tAfter call memmove:\n");
			i = 0;
			printf("\tmemmove ->    src -> ");
			while(i < 10)
				printf("%c", src[i++]);
			i = 0;
			printf(" dst -> ");
			while(i < 10)
				printf("%c", dst1[i++]);
			printf("\n");
			printf("\tft_memmove -> src -> ");
			i = 0;
			while(i < 10)
				printf("%c", src[i++]);
			i = 0;
			printf("\tdst -> ");
			while(i < 10)
				printf("%c", dst2[i++]);
			printf("\n");
			printf("\t--PASS--\n");
	}
	else
	{
			printf("\t**FAIL**\n");
			i = 0;
			while(i < 10)
				printf("%c", dst1[i++]);
			printf("\n");
			i = 0;
			while(i < 10)
				printf("%c", dst2[i++]);
			printf("\n");
	}
	d1 = &src[6];
	d2 = &src[6];
	printf("\t*_input -> dst = &src[6], src = ABCDEFGHIJ, 10\n");
	if (memcmp((char *)memmove(d1, src, 3), (char *)ft_memmove(d2, src, 10), 3) == 0)
	{
			printf("\t--PASS--\n");
			i = 0;
			printf("\tmemmove ->    ");
			while(i < 10)
				printf("%c", d1[i++]);
			printf("\n");
			printf("\tft_memmove -> ");
			i = 0;
			while(i < 10)
				printf("%c", d2[i++]);
			printf("\n");
	}
	else
	{
			printf("\t**FAIL**\n");
			i = 0;
			while(i < 10)
				printf("%c", d1[i++]);
			printf("\n");
			i = 0;
			while(i < 10)
				printf("%c", d2[i++]);
	}
}
