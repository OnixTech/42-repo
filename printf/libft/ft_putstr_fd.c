/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:09:17 by luciano           #+#    #+#             */
/*   Updated: 2026/01/10 19:13:20 by lupetill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return (ft_putstr_fd("(null)", 1));
	i = ft_strlen(s);
	write(fd, s, i);
	return (i);
}
