/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:44:43 by lupetill          #+#    #+#             */
/*   Updated: 2025/12/03 23:16:27 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	trimlen(char const *s1, char const *set, size_t *len, size_t *i)
{
	size_t	s1l;
	size_t	start;
	size_t	end;

	s1l = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = s1l;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	*i = start;
	*len = end - start;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	i;

	trimlen(s1, set, &len, &i);
	if (!s1)
	{
		str = (char *)malloc(sizeof(char) * (1));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s1 + i, len + 1);
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*set;

	s1 = "Hoyetla como estas loyetco";
	set = "yet";
	printf("%s\n",ft_strtrim(s1, set));
	return (0);
}*/
