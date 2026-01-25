/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupetill <lupetill@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:54:10 by lupetill          #+#    #+#             */
/*   Updated: 2026/01/10 19:07:57 by lupetill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putptr(void *ptr);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putu(size_t n);
int		ft_puthexa(size_t n, char format);
size_t	ft_strlen(const char *s);

#endif
