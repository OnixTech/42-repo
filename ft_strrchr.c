/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 21:16:48 by luciano           #+#    #+#             */
/*   Updated: 2025/11/30 21:57:41 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned int    i;
	char	*a;

	a = 0;
	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == (unsigned char)s[i])
			a = (char *)(s + i);
		i++;
	}
	if ((unsigned char)c == '\0' && *a == 0)
		return (char *)(s + i);
	return (a);
}
