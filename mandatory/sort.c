/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:44:06 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/01 21:32:49 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void    sort_two(t_stack *stack_a)
{
    if (stack_a->array[0] > stack_a->array[1])
        {
            ft_swap(stack_a);
            write(1, "sa\n", 3);
        }
}
void    sort_three(t_stack *stack_a)
{
    if (stack_a->array[0] > stack_a->array[1] && stack_a->array[1] < stack_a->array[2] 
        && stack_a->array[0] < stack_a->array[2])
        {
            ft_swap(stack_a);
            write(1, "sa\n", 3);
        }
    else if (stack_a->array[0] > stack_a->array[1] && stack_a->array[1] > stack_a->array[2])
    {
        ft_swap(stack_a);
        ft_reverse_rotate(stack_a);
        write(1, "sa\nrra\n", 7);
    }
    else if (stack_a->array[0] > stack_a->array[1] 
            && stack_a->array[1] < stack_a->array[2] && stack_a->array[0] > stack_a->array[2])
            {
                ft_rotate(stack_a);
                write(1, "ra\n", 3);
            }
    else if (stack_a->array[0] < stack_a->array[1] && stack_a->array[1] > stack_a->array[2]
            && stack_a->array[0] < stack_a->array[2])
    {
        ft_swap(stack_a);
        ft_rotate(stack_a);
        write(1, "sa\nra\n", 6);
    }
    else if (stack_a->array[0] < stack_a->array[1] && stack_a->array[1] > stack_a->array[2] 
            && stack_a->array[0] > stack_a->array[2])
        {
            ft_reverse_rotate(stack_a);
            write(1, "rra\n", 4);
        }
}
void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    int smallest;
    int i;

    while (stack_a->size > 3)
    {
        smallest = 0;
        i = 1;
        while (i < stack_a->size)
        {
            if (stack_a->array[i] < stack_a->array[smallest])
                smallest = i;
            i++;
        }
        if (smallest <= stack_a->size / 2)
        {
            while (smallest > 0)
            {
                ft_rotate(stack_a);
                write(1, "ra\n", 3);
                smallest--;
            }
        }
        else
        {
            while (smallest < stack_a->size)
            {
                ft_reverse_rotate(stack_a);
                write(1, "rra\n", 4);
                smallest++;
            }
        }
        ft_push(stack_a, stack_b);
        write(1, "pb\n", 3);
    }
    sort_three(stack_a);
    while (stack_b->size > 0)
    {
        ft_push(stack_b, stack_a);
        write(1, "pa\n", 3);
    }
}

void sort(t_stack *stack_a , t_stack *stack_b)
{
    (void)stack_b;
    if (stack_a->size < 2)
        return ;
    if (stack_a->size == 2)
        sort_two(stack_a);
    if (stack_a->size == 3)
        sort_three(stack_a);
    if (stack_a->size > 3)
        sort_five(stack_a, stack_b);
}