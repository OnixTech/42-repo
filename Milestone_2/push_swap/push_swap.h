/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:13 by luciano           #+#    #+#             */
/*   Updated: 2026/03/08 10:57:48 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_isdigit(char *c);
int	parse_input(int arg, char **argc, int *size, int **input);
int	parse_string(char *argc, int *size, int **input);
int	parse_args(int arg, char **str, int **size, int **input);
void	push_swap(int	*input, int size);
int	string_validation(char *argc, int **size);
int	ft_digit_sign(char *c);
int	ft_sign(char *c);
int intjoin(char *str, int size, int **input, int i);
long	ft_atoi(char *str);
int args_validation(int arg, char **argc, int **size);

#endif /* PUSH_SWAP_H */
