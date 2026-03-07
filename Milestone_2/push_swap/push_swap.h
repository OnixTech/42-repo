/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:13 by luciano           #+#    #+#             */
/*   Updated: 2026/03/07 12:25:04 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include	<stdlib.h>

int	ft_isdigit(char *c);
int	parse_input(int arg, char **argc, int *size, int **input);
int	parse_string(char *argc, int *size, int **input);
int	parse_args(int arg, char *argc);
void	push_swap(int	*input, int size);
int	string_validation(char *argc, int **size);
int	ft_digit_sign(char *c);
int	ft_sign(char *c);
int intjoin(char *str, int size, int **input);
long	ft_atoi(char *str);

#endif /* PUSH_SWAP_H */
