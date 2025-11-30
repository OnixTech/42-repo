/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:42:39 by lupetill          #+#    #+#             */
/*   Updated: 2025/11/30 21:11:22 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <bsd/string.h>
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
void	test_strlcpy(void);
void	test_strlcat(void);
void	test_toupper(void);
void	test_tolower(void);
void	test_strchr(void);

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
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	test_strchr();
	return (0);
}

void	test_alpha(void)
{
	char	*c;
	int		i;

	i = 0;
	c = "abcdefghijklmnopqrstuvwxyz";
	printf("#_ FUNTION isalpha:\n\t*_inputs -> 'a' 'b' 'c'...'z'\n");
	while (c[i++])
	{
		if (ft_isalpha(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break ;
		}
		if (!c[i])
			printf("\t--PASS--\n");
	}
	i = 0;
	c = "0 0123456789´?*#!&%712";
	printf("\t*_inputs -> 0123456789´?*#!&712\n");
	while (c[i++])
	{
		if (!c[i])
		{
			printf("\t--PASS--\n");
			break ;
		}
		if (!ft_isalpha(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break ;
		}
	}
}

void	test_digit(void)
{
	char	*c;
	int		i;

	i = 0;
	c = "0123456789";
	printf("#_ FUNTION isdigit:\n\t*_inputs -> '1' '2' '3'...'0'\n");
	while (c[i++])
	{
		if (ft_isdigit(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break ;
		}
		if (!c[i])
			printf("\t--PASS--\n");
	}
	i = 0;
	c = "abcdefghijklmnopqtuvwxyz´?*#!&";
	printf("\t*_inputs -> abcdefghijklmnopqtuvwxyz´?*#!&\n");
	while (c[i++])
	{
		if (!c[i])
		{
			printf("\t--PASS--\n");
			break ;
		}
		if (!ft_isdigit(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break ;
		}
	}
}

void	test_alnum(void)
{
	char	*c;
	int		i;

	i = 0;
	c = "01d2b34a56cz789";
	printf("#_ FUNTION isalnum:\n\t*_inputs -> 01d2b34a56cz789\n");
	while (c[i])
	{
		if (ft_isalnum(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break ;
		}
		if (!c[i])
			printf("\t--PASS--\n");
	}
	i = 0;
	c = "();,.§´?*#!&";
	printf("\t*_inputs -> ();,.§´?*#!&\n");
	while (c[i])
	{
		if (!ft_isalnum(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %c\n", c[i]);
			break ;
		}
		if (!c[i])
		{
			printf("\t--PASS--\n");
			break ;
		}
	}
}

void	test_isascii(void)
{
	int	c[128];
	int	i;

	i = -1;
	while (i++ < 127)
		c[i] = i;
	printf("#_ FUNTION isascii:\n\t*_inputs -> '0' '1' '2'...'127'\n");
	i = 0;
	while (i < 128)
	{
		if (ft_isascii(c[i]))
			i++;
		else
		{
			printf("\tFAIL IN -> %d\n", c[i]);
			break ;
		}
		if (i == 128)
			printf("\t--PASS--\n");
	}
	printf("\t*_input -> '-1' '128'\n");
	if (!ft_isascii(-1))
		if (!ft_isascii(128))
			printf("\t--PASS--\n");
}

void	test_isprint(void)
{
	int	c[97];
	int	i;

	i = 31;
	while (i++ < 127)
		c[i - 32] = i;
	printf("#_ FUNTION isprint:\n\t*_inputs -> '32' '33' '34'...'126'\n");
	i = 32;
	while (i < 127)
	{
		if (ft_isprint(c[i - 32]))
			i++;
		else
		{
			printf("\tFAIL IN -> %d\n", c[i - 32]);
			break ;
		}
		if (i == 127)
			printf("\t--PASS--\n");
	}
	printf("\t*_input -> '31' '127'\n");
	if (!ft_isprint(31))
	{
		if (!ft_isprint(127))
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
	while (++i < n)
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
		while (i < n)
			printf("%x", arr1[i++]);
		printf("\n");
		i = 0;
		while (i < n)
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
	while (++i < n)
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
		while (i < n)
			printf("%x", arr1[i++]);
		printf("\n");
		i = 0;
		while (i < n)
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
		while (i < n)
			printf("%x", arr1[i++]);
		printf("\n");
		i = 0;
		while (i < n)
			printf("%x", arr2[i++]);
	}
}

void	test_memcpy(void)
{
	unsigned char	src[10];
	unsigned char	dst1[10];
	unsigned char	dst2[10];
	int				i;

	printf("#_ FUNTION memcpy:\n\t*_input -> dst[10], src = 0 1 2...9, sizeof(dst)\n");
	i = 0;
	while (i < 10)
	{
		dst1[i] = 0xff;
		dst2[i] = 0xff;
		src[i] = 0 + i;
		i++;
	}
	if (memcmp((char *)memcpy(dst1, src, sizeof(dst1)), (char *)ft_memcpy(dst2,
				src, sizeof(dst2)), sizeof(dst1)) == 0)
	{
		printf("\t--PASS--\n");
		i = 0;
		printf("\tmemcpy ->    ");
		while (i < 10)
			printf("%x", dst1[i++]);
		printf("\n");
		printf("\tft_memcpy -> ");
		i = 0;
		while (i < 10)
			printf("%x", dst2[i++]);
		printf("\n");
	}
	else
	{
		printf("\t**FAIL**\n");
		i = 0;
		while (i < 10)
			printf("%c", dst1[i++]);
		printf("\n");
		i = 0;
		while (i < 10)
			printf("%c", dst2[i++]);
	}
}

void	test_memmove(void)
{
	unsigned char	src[10];
	unsigned char	src1[] = {"ABCDEFGHIJ"};
	unsigned char	src2[] = {"ABCDEFGHIJ"};
	unsigned char	dst1[10];
	unsigned char	dst2[10];
	unsigned char	*d1;
	unsigned char	*d2;
	int				i;

	printf("#_ FUNTION memmove:\n\t*_input -> dst = KLMNOPQRST, src = ABCDEFGHIJ, 10\n");
	i = 0;
	while (i < 10)
	{
		src[i] = 'A' + i;
		dst1[i] = 'K' + i;
		dst2[i] = 'K' + i;
		i++;
	}
	i = 0;
	printf("\tBefore call memmove:\n");
	printf("\tmemmove ->    src -> ");
	while (i < 10)
		printf("%c", src[i++]);
	i = 0;
	printf(" dst -> ");
	while (i < 10)
		printf("%c", dst1[i++]);
	printf("\n");
	printf("\tft_memmove -> src -> ");
	i = 0;
	while (i < 10)
		printf("%c", src[i++]);
	i = 0;
	printf("\tdst -> ");
	while (i < 10)
		printf("%c", dst2[i++]);
	printf("\n");
	if (memcmp((char *)memmove(dst1, src, 10), (char *)ft_memmove(dst2, src,
				10), 10) == 0)
	{
		printf("\tAfter call memmove:\n");
		i = 0;
		printf("\tmemmove ->    src -> ");
		while (i < 10)
			printf("%c", src[i++]);
		i = 0;
		printf(" dst -> ");
		while (i < 10)
			printf("%c", dst1[i++]);
		printf("\n");
		printf("\tft_memmove -> src -> ");
		i = 0;
		while (i < 10)
			printf("%c", src[i++]);
		i = 0;
		printf("\tdst -> ");
		while (i < 10)
			printf("%c", dst2[i++]);
		printf("\n");
		printf("\t--PASS--\n");
	}
	else
	{
		printf("\t**FAIL**\n");
		i = 0;
		while (i < 10)
			printf("%c", dst1[i++]);
		printf("\n");
		i = 0;
		while (i < 10)
			printf("%c", dst2[i++]);
		printf("\n");
	}
	d1 = &src1[6];
	d2 = &src2[6];
	printf("\t*_input -> dst = &src[6], src = ABCDEFGHIJ, 3\n");
	if (memcmp((char *)memmove(d1, src1, 3), (char *)ft_memmove(d2, src2, 3),
			3) == 0)
	{
		printf("\t--PASS--\n");
		i = 0;
		printf("\tmemmove ->    ");
		while (i < 3)
			printf("%c", d1[i++]);
		printf("\n");
		printf("\tft_memmove -> ");
		i = 0;
		while (i < 3)
			printf("%c", d2[i++]);
		printf("\n");
	}
	else
	{
		printf("\t**FAIL**\n");
		i = 0;
		while (i < 3)
			printf("%c", d1[i++]);
		printf("\n");
		i = 0;
		while (i < 3)
			printf("%c", d2[i++]);
	}
}

void	test_strlcpy(void)
{
	char			dest_size;
	char			dest1[8];
	char			dest2[8];
	char			src[] = {"DEFG"};
	size_t	a;
	size_t	b;
	int	i;

	dest_size = 8;
	while (i < 3)
	{
		dest1[i] = 'A' + i;
		dest2[i] = 'A' + i;
		i++;
	}
	a = strlcpy(&dest1[0], &src[0], dest_size);
	b = ft_strlcpy(&dest2[0], &src[0], dest_size);
	printf("#_ FUNTION strlcpy:\n\t*_input -> dst[8] = ABC, src = DEFG, n = 4\n");
	if (strcmp(dest1, dest2) == 0)
	{
		printf("\tstrlcpy return -> %zu\n", a);
		printf("\tdst = %s\n", dest1);
		printf("\tft_strlcpy return -> %zu\n", b);
		printf("\tdst = %s\n", dest2);
		printf("\t--PASS--\n");
	}
	else
	{
		printf("\t**FAIL**\n");
		printf("\treturn -> %zu", b);
		printf("\ndst = %s", dest2);
	}
}

void	test_strlcat(void)
{
	char			dest_size;
	char			dest_size2;
	char			str1[] = {"Hola, como"};
	char			str2[] = {"Hola, como esta el"};
	char			dest1[18];
	char			dest2[18];
	char			dest3[28];
	char			dest4[28];
	char			src[] = {" estas?"};
	char			src2[] = {" el nene?"};
	unsigned int	a;
	unsigned int	b;
	int	i;

	dest_size = 18;
	dest_size2 = 28;
	i = 0;
	while (str1[i])
	{
		dest1[i] = str1[i];
		dest2[i] = str1[i];
		i++;
	}
	dest1[i] = '\0';
	dest2[i] = '\0';
	i = 0;
	while (str2[i])
	{
		dest3[i] = str2[i];
		dest4[i] = str2[i];
		i++;
	}	
	dest3[i] = '\0';
	dest4[i] = '\0';
	a = strlcat(&dest1[0], &src[0], dest_size);
	b = ft_strlcat(&dest2[0], &src[0], dest_size);
	printf("#_ FUNTION strlcat:\n\t*_input -> dst[18] = 'Hola, como', src = ' estas?', size = 18\n");
	if (strcmp(dest1, dest2) == 0)
	{
		printf("\tstrlcat return -> %i\n", a);
		printf("\tdst = %s\n", dest1);
		printf("\tft_strlcat return -> %i\n", b);
		printf("\tdst = %s\n", dest2);
		printf("\t--PASS--\n");
	}
	else
	{
		printf("\t**FAIL**\n");
		printf("\tstrlcat return -> %i\n", a);
		printf("\tdst = %s\n", dest1);
		printf("\tft_strlcat return -> %i\n", b);
		printf("\tdst = %s\n", dest2);
	}
	a = strlcat(dest1, src2, dest_size);
	b = ft_strlcat(dest2, src2, dest_size);
	printf("\t*_input -> dst[28] = 'Hola, como esta', src = ' el nene?', size = 28 | size - dst length - 1 < 0\n");
	if (strcmp(dest1, dest2) == 0)
	{
		printf("\tstrlcat return -> %i\n", a);
		printf("\tdst = %s\n", dest3);
		printf("\tft_strlcat return -> %i\n", b);
		printf("\tdst = %s\n", dest4);
		printf("\t--PASS--\n");
	}
	else
	{
		printf("\t**FAIL**\n");
		printf("\treturn -> %i\n", a);
		printf("\tdst = %s\n", dest3);
		printf("\treturn -> %i\n", b);
		printf("\tdst = %s\n", dest4);
	}
}

void	test_toupper(void)
{
	char	c;
		
	printf("#_ FUNTION toupper:\n\t*_input -> c = A, B, C, ...Z\n");
	c = 'A';
	while (c <= 'Z')
	{
		if (ft_toupper(c) == c)
			c++;
		else
			break;
	}
	if (c == 'Z' + 1)
		printf("\t--PASS--\n");	
	else
	{
		printf("\t**FAIL**\n");
		printf("\treturn -> %i\n", ft_toupper(c));
	}
	printf("\t*_input -> c = a, b c, ...z\n");
	c = 'a';
	while (c <= 'z')
	{
		if (ft_toupper(c) == c - 32)
			c++;
		else
			break;
	}
	if (c == 'z' + 1)
		printf("\t--PASS--\n");	
	else
	{
		printf("\t**FAIL**\n");
		printf("\treturn -> %i\n",ft_toupper(c));
	}
}

void	test_tolower(void)
{
	char	c;
		
	printf("#_ FUNTION toupper:\n\t*_input -> c = a, b, c, ...z\n");
	c = 'a';
	while (c <= 'z')
	{
		if (ft_tolower(c) == c)
			c++;
		else
			break;
	}
	if (c == 'z' + 1)
		printf("\t--PASS--\n");	
	else
	{
		printf("\t**FAIL**\n");
		printf("\treturn -> %i\n", ft_toupper(c));
	}
	printf("\t*_input -> c = A, B C, ...Z\n");
	c = 'A';
	while (c <= 'Z')
	{
		if (ft_tolower(c) == c + 32)
			c++;
		else
			break;
	}
	if (c == 'Z' + 1)
		printf("\t--PASS--\n");	
	else
	{
		printf("\t**FAIL**\n");
		printf("\tc = %i return -> %i\n", c, ft_tolower(c));
	}
}

void	test_strchr(void)
{
	char	s[] = "Hola, como estas?";

	printf("#_ FUNCTION strchr:\n\t*_input -> s = Hola, como estas?, c = m\n");
	if (strcmp(ft_strchr(s, 'm'), strchr(s, 'm')) == 0)
		printf("\t--PASS--\n");
	else
	{
		printf("\t**FAIL**\n");
		printf("\t strchr return -> %s\n", strchr(s, 'm'));
		printf("\t ft_strchr return -> %s\n", ft_strchr(s, 'm'));
	}
	printf("\n\t*_input -> s = Hola, como estas?, c = \\0\n");
	if (strcmp(ft_strchr(s, '\0'), strchr(s, '\0')) == 0)
		printf("\t--PASS--\n");
	else
	{	
		printf("\t**FAIL**\n");	
		printf("\t strchr return -> %s\n", strchr(s, '\0'));
		printf("\t ft_strchr return -> %s\n", ft_strchr(s, '\0'));
	}
	printf("\n\t*_input -> s = Hola, como estas, c = y\n");
	if (ft_strchr(s, 'y') == NULL)
		printf("\t--PASS--\n");
	else
	{	
		printf("\t**FAIL**\n");	
		printf("\t strchr return -> %s\n", strchr(s, 'y'));
		printf("\t ft_strchr return -> %s\n", ft_strchr(s, 'y'));
	}
}
