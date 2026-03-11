/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:13 by luciano           #+#    #+#             */
/*   Updated: 2026/03/11 22:20:51 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	init(int **stack_a, int *size_a, int **stack_b, int *size_b);
void	end(int **stack_a, int **stack_b);
int		init_stack_b(int size_a, int **stack_b, int *size_b);
int		error(int **stack_a, int **stack_b);
int		ft_isdigit(char *c);
int		parse_input(int arg, char **argc, int *size, int **input);
int		parse_string(char *argc, int *size, int **input);
int		parse_args(int arg, char **str, int *size, int **input);
int		sort(int **stack_a, int *size_a, int **stack_b, int *size_b);
int		string_validation(char *argc, int *size);
int		ft_digit_sign(char *c);
int		ft_sign(char *c);
int		str_intjoin(char *str, int size, int **input);
long	ft_atoi(char *str);
int		args_validation(int arg, char **argc, int *size);
int		args_intjoin(char **str, int size, int **input);
int		duplicate_input(int i, long number, int **input);

#endif /* PUSH_SWAP_H */
