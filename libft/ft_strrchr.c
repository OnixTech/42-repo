/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 21:16:48 by luciano           #+#    #+#             */
/*   Updated: 2025/12/02 16:10:08 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	ch = (char)c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (1)
	{
		if (ch == s[i])
			return ((char *)(s + i));
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
