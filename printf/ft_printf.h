/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:54:10 by lupetill          #+#    #+#             */
/*   Updated: 2026/01/04 22:40:57 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *, ...);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_printhexa(void *ptr);

#endif
