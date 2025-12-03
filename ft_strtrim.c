/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:44:43 by lupetill          #+#    #+#             */
/*   Updated: 2025/12/03 15:25:19 by lupetill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s1l;
	size_t	setl;
	size_t	i;
	size_t	j;
	size_t	strl;

	setl = ft_strlen(set);
	if (ft_strncmp(ft_strchr(s1, set[0]), set, setl) == 0)
		i = ft_strchr(s1, set[0]) - s1 + setl;
	s1l = ft_strlen(s1);
	if (ft_strncmp(ft_strrchr(s1, set[0]), set, setl) == 0)
		j = s1 - ft_strrchr(s1, set[0]);
	str = (char *)malloc(sizeof(char) * (s1l - i - j));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + i, s1l - i - j);
	return (str);
}

#include <stdio.h>
int	main(void)
{
	char	*s1;
	char	*set;

	s1 = "Hoyetla como estas locoyet eeeeh";
	set = "yet";
	printf("%s",ft_strtrim(s1, set));
	return (0);
}
