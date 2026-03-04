/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:13 by luciano           #+#    #+#             */
/*   Updated: 2026/03/04 13:29:23 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include	<stdlib.h>

int	ft_isdigit(char *c);
int	*parse_input(int arg, char **argc);
int	*parse_string(char *argc);
int	*parse_args(int arg, char *argc);
void	push_swap(int	*input);

#endif /* PUSH_SWAP_H */
