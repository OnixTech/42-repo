/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:32:46 by luciano           #+#    #+#             */
/*   Updated: 2026/03/25 16:36:45 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rr(t_data *stack)
{
        ra(stack);
        rb(stack);
}

void    rrr(t_data *stack)
{
        rra(stack);
        rrb(stack);
}

void sort_two(t_data *stack)
{
        if (stack->a[0] > stack->a[1])
                sa(stack);                                                      
}

void sort_three(t_data *stack)
{
        int     a;
        int     b;
        int     c;

        a = stack->a[0];
        b = stack->a[1];
        c = stack->a[2];
        if (a < b && b < c)
                return ;
        if (a > b && b > c)
        {
                sa(stack);
                rra(stack);
        }
        if (a > b && a > c && c > b)
                ra(stack);
        if (c > a && c > b && a > b)
                sa(stack);
        if (b > a && b > c && c > a)
        {
                rra(stack);
                sa(stack);
        }
        if (b > a && b > c && a > c)
                rra(stack);
}

void sort_four_five(t_data *stack)
{
        int     min;

        min = min_val(stack);
        push_min(stack, min);
        if (stack->size_a == 4)
        {
                min = min_val(stack);
                push_min(stack, min);
        }
                sort_three(stack);
                pa(stack);
        if (stack->size_b)
                pa(stack);
}
