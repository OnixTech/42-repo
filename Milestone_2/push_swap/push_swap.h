/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:13 by luciano           #+#    #+#             */
/*   Updated: 2026/03/31 13:16:07 by luciano          ###   ########.fr       */
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
	int	pb_counter;
	int	operations;
}		t_data;

/******************************     utils.c      ******************************/
int		ft_isdigit(char *c);
int		ft_sign(char *c);
int		ft_digit_sign(char *c);
long	ft_atoi(char *str);
int		duplicate_input(int i, long number, t_data *stack);
/******************************************************************************/

/******************************    utils_2.c     ******************************/
int		error(t_data *stack);
void	init(t_data *stack);
int		init_stack(t_data *stack);
void	end(t_data *stack);
/******************************************************************************/

/*******************************    utils_3.c    ******************************/
void	shift_down(int *stack, int i);
void	shift_up(int *stack, int size);
/******************************************************************************/

/******************************* input_handler.c ******************************/
int		parse_input(int arg, char **argc, t_data *stack);
int		parse_string(char *argc, t_data *stack);
int		parse_args(int arg, char **str, t_data *stack);
/******************************************************************************/

/******************************* string_utils.c  ******************************/
int		string_validation(char *argc, t_data *stack);
int		str_intjoin(char *str, t_data *stack);
/******************************************************************************/

/*******************************   args_utils.c  ******************************/
int		args_validation(int arg, char **argc, t_data *stack);
int		arg_intjoin(char **str, t_data *stack);
/******************************************************************************/

/*******************************   operations.c.  *****************************/
void	sa(t_data *stack);
void	sb(t_data *stack);
void	ss(t_data *stack);
void	pa(t_data *stack);
void	pb(t_data *stack);
/******************************************************************************/

/*******************************  operations_2.c  *****************************/
void	ra(t_data *stack);
void	rb(t_data *stack);
void	rra(t_data *stack);
void	rrb(t_data *stack);
/******************************************************************************/

/*******************************  operations_3.c  *****************************/
void	sort_two(t_data *stack);
void	sort_three(t_data *stack);
void	sort_four_five(t_data *stack);
void	rr(t_data *stack);
void	rrr(t_data *stack);
/******************************************************************************/

/*******************************    push_swap.c   *****************************/
void		sort(t_data *stack);
int		is_sorted(t_data *stack);
/******************************************************************************/

/*******************************  sort_helpers.c. *****************************/
void	push_min(t_data *stack, int min);
int		min_val(t_data *stack);
void		get_scheme(t_data *stack, int **scheme);
void		stack_indexed(t_data *stack);
/******************************************************************************/

/*******************************     chunks.c.    *****************************/
void	chunks(t_data *stack);
int	chunks_size(t_data *stack);
void	push_chunk_b(t_data *stack, int  ch_size);
/******************************************************************************/

#endif /* PUSH_SWAP_H */
