/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozox <rozox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:48:22 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/11 14:04:17 by rozox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int find_min_index(t_stack *stack)
{
    int i;
    int min_index = 0;

    for (i = 1; i < stack->size; i++)
    {
        if (stack->array[i] < stack->array[min_index])
            min_index = i;
    }
    return (min_index);
}

void calculate_positions(t_stack *stack_a, t_stack *stack_b)
{
    int i, j;

    // Update positions in stack_a
    for (i = 0; i < stack_a->size; i++)
        stack_a->array[i] = i;

    // Calculate target positions for stack_b
    for (i = 0; i < stack_b->size; i++)
    {
        stack_b->pos = i;
        stack_b->target_pos = 0;
        for (j = 0; j < stack_a->size; j++)
        {
            if (stack_a->array[j] > stack_b->array[i] &&
                (stack_a->target_pos == 0 || stack_a->array[j] < stack_a->array[stack_b->target_pos]))
            {
                stack_b->target_pos = j;
            }
        }
        if (stack_b->target_pos == 0)
            stack_b->target_pos = find_min_index(stack_a);
    }
}
void calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
    for (int i = 0; i < stack_b->size; i++)
    {
        stack_b->cost_b = (stack_b->pos <= stack_b->size / 2) ? stack_b->pos : stack_b->pos - stack_b->size;
        stack_b->cost_a = (stack_b->target_pos <= stack_a->size / 2) ? stack_b->target_pos : stack_b->target_pos - stack_a->size;
    }
}
void execute_best_move(t_stack *stack_a, t_stack *stack_b)
{
    int best_index = 0;
    int min_cost = abs(stack_b->cost_a[0]) + abs(stack_b->cost_b[0]);

    for (int i = 1; i < stack_b->size; i++)
    {
        int total_cost = abs(stack_b->cost_a[i]) + abs(stack_b->cost_b[i]);
        if (total_cost < min_cost)
        {
            min_cost = total_cost;
            best_index = i;
        }
    }
    while (stack_b->cost_a[best_index] > 0 && stack_b->cost_b[best_index] > 0)
        do_rr(stack_a, stack_b);
    while (stack_b->cost_a[best_index] < 0 && stack_b->cost_b[best_index] < 0)
        do_rrr(stack_a, stack_b);
    while (stack_b->cost_a[best_index] > 0)
        do_ra(stack_a);
    while (stack_b->cost_a[best_index] < 0) 
        do_rra(stack_a);
    while (stack_b->cost_b[best_index] > 0) 
        do_rb(stack_b);
    while (stack_b->cost_b[best_index] < 0) 
        do_rrb(stack_b);
    do_pa(stack_b, stack_a);
}

void finalize_stack_a(t_stack *stack_a)
{
    int min_index = find_min_index(stack_a);

    if (min_index <= stack_a->size / 2)
    {
        while (min_index--)
            do_ra(stack_a);
    }
    else
    {
        while (min_index++ < stack_a->size)
            do_rra(stack_a);
    }
}
