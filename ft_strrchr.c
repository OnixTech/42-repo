/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 21:16:48 by luciano           #+#    #+#             */
/*   Updated: 2025/12/01 18:13:17 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int    i;

	i = ft_strlen(s);	
	while (i > 0)
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return (char *)(s + i);
		i--;
	}
	if ((unsigned char)c == (unsigned char)s[i])
		return (char *)(s + i);
	if ((unsigned char)c == '\0')
		return (NULL);
	return (NULL);
}
