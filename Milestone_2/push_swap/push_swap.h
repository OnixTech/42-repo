/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:13 by luciano           #+#    #+#             */
/*   Updated: 2026/03/12 14:38:48 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	capacity;
}		t_data;

/********************     utils.c.    ********************/
int		ft_isdigit(char *c);
int		ft_sign(char *c);
int		ft_digit_sign(char *c);
long	ft_atoi(char *str);
int		duplicate_input(int i, long number, t_data *stack);
/********************    utils_2.c.   ********************/
int		error(t_data *stack);
void	init(t_data *stack);
int		init_stack(t_data *stack);
void	end(t_data *stack);
/******************** input_handler.c ********************/
int		parse_input(int arg, char **argc, t_data *stack);
int		parse_string(char *argc, t_data *stack);
int		parse_args(int arg, char **str, t_data *stack);
/******************** string_utils.c  ********************/
int		string_validation(char *argc, t_data *stack);
int		str_intjoin(char *str, t_data *stack);
/********************   args_utils.c  ********************/
int		args_validation(int arg, char **argc, t_data *stack);
int		arg_intjoin(char **str, t_data *stack);
/********************   push_swap.c.  ********************/
int		sort(t_data *stack);

#endif /* PUSH_SWAP_H */
