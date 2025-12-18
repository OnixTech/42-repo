/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:24:18 by luciano           #+#    #+#             */
/*   Updated: 2025/12/02 18:20:41 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (i < len && haystack[i])
	{
		while (needle[j] == haystack[j + i] && haystack[j + i] && (i + j < len))
		{
			j++;
			if (!needle[j])
				return ((char *)(haystack + i));
		}
		if (needle[j])
			j = 0;
		i++;
	}
	return (NULL);
}
