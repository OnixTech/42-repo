/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:49:08 by lupetill          #+#    #+#             */
/*   Updated: 2025/12/03 13:36:45 by lupetill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1l;
	size_t	s2l;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1l + s2l + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1l + 1);
	ft_strlcpy(str + s1l, s2, s2l + 1);
	str[s1l + s2l + 1] = '\0';
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "Hola, ";
	s2 = "como estas?";

	printf("%s\n", ft_strjoin(s1, s2));
	s1 = "Hola";
	s2 = "";

	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
	return (0);
}*/
