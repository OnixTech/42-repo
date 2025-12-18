/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 08:01:46 by luciano           #+#    #+#             */
/*   Updated: 2025/12/08 12:06:17 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (!s[i])
		return (0);
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**str;

	str = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (!str || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			str[i++] = ft_substr(s, 0, len);
			s += len;
		}
	}
	str[i] = NULL;
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	c;
	char	**sp;
	str = "      split       this for   me  !       ";
	c = ' ';
	sp = ft_split(str, c);
	while (*sp)
		printf("%s\n", *sp++);
	return (0);
}*/
