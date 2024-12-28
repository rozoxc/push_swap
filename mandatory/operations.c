/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:58:15 by ababdoul          #+#    #+#             */
/*   Updated: 2024/12/24 16:18:15 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_swap(t_stack *stack_a)
{
    int tmp;

    if (stack_a->size < 1)
        return ;
    tmp = stack_a->array[0];
    stack_a->array[0] = stack_a->array[1];
    stack_a->array[1] = tmp;
}

void ft_push(t_stack *src, t_stack *dest)
{
    int i;

    i = dest->size;
    if (src->size < 1)
        return ;
    while (i > 0)
    {
        dest->array[i] = dest->array[i - 1];
        i--; 
    }
    dest->array[0] = src->array[0];
    i = 0;
    while (i < src->size - 1)
    {
        src->array[i] = src->array[i + 1];
        i++;
    }
    src->size--;
    dest->size++;
}

void ft_rotate(t_stack *stack)
{
    int tmp;
    int i;

    if (stack->size < 2)
        return ;
    tmp = stack->array[0];
    i = 0;
    while (i < stack->size - 1)
    {
        stack->array[i] = stack->array[i + 1];
        i++;
    }
    stack->array[i] = tmp;
}

void ft_reverse_rotate(t_stack *stack)
{
    int tmp;
    int i;

    if (stack->size < 2)
        return ;
    tmp = stack->array[stack->size - 1];
    i = stack->size - 1;
    while (i > 0)
    {
        stack->array[i] = stack->array[i - 1];
        i--;
    }
    stack->array[0] = tmp;
}