/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:54:10 by lupetill          #+#    #+#             */
/*   Updated: 2026/01/05 20:23:08 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *, ...);
size_t	ft_strlen(const char *s);
int	ft_putchar(char c, int fd);
int	ft_putptr(void *ptr);
int	ft_putstr(char *s);
void	*ft_memset(void	*b, int c, size_t len);
#endif
