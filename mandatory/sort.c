/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozox <rozox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:44:06 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/11 14:03:31 by rozox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_two(t_stack *stack)
{
    if (stack->array[0] > stack->array[1])
    {
        if (stack->index_stack == 0)
            do_sa(stack);
        else
            do_sb(stack);
    }
}
void sort_three(t_stack *stack)
{
    if (stack->array[0] > stack->array[1] && stack->array[0] > stack->array[2])
    {
        if (stack->index_stack == 0)
            do_ra(stack);
        else
            do_rb(stack);
    }
    if (stack->array[1] > stack->array[2] && stack->array[1] > stack->array[0])
    {
        if (stack->index_stack == 0)
            do_rra(stack);
        else
            do_rrb(stack);
    }
    if (stack->array[0] > stack->array[1])
    {
        if (stack->index_stack == 0)
            do_sa(stack);
        else
            do_sb(stack);
    }
}

void sort_more_than_three(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_a->size > 3)
        do_pb(stack_a, stack_b);
    sort_three(stack_a);
    while (stack_b->size > 0)
    {
        calculate_positions(stack_a, stack_b);
        calculate_costs(stack_a, stack_b);
        execute_best_move(stack_a, stack_b);
    }
    finalize_stack_a(stack_a);
}

void sort(t_stack *stack_a , t_stack *stack_b)
{
    (void)stack_b;
    if (stack_a->size <= 1)
        return ;
    else if (stack_a->size == 2)
        sort_two(stack_a);
    else if(stack_a->size == 3)
        sort_three(stack_a);
    else if (stack_a->size >= 3)
        sort_more_than_three(stack_a , stack_b);
    
}
