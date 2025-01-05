/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozox <rozox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:44:06 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/05 19:51:44 by rozox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int find_min(t_stack *stack)
{
    int i;
    int min;

    i = 0;// stack = 0 1 2 3 4 5 6 -1
    while (i < stack->size)// 0 < 8
    {
       if (stack->array[i] < stack->array[i + 1])
            min = stack->array[i];
        i++;
    }
    return (min);
}
void sort_two(t_stack *stack)
{
    if (stack->array[0] > stack->array[1])
    {
        ft_swap(stack);
        if (stack->index == 0)
            write(1, "sa\n", 3);
        else if (stack->index == 1)
            write(1, "sb\n", 3);
    }
    else
        return ;
}
void sort_max(t_stack *stack)
{
    int i;
    int min;

    min = find_min(stack);
    i = 0;
    // printf("minimal value in stack is : %d \n", i);
    while (i < stack->size)
    {
        
    }
}
void    sort(t_stack *stack_a, t_stack *stack_b)
{
    (void)stack_b;
    printf("size in sort alg : %d\n", stack_a->size);
    if (stack_a->size <= 1)
        return ;
    else if (stack_a->size == 2)
        sort_two(stack_a);
    else if (stack_a->size >= 3)
        sort_max(stack_a);
}
