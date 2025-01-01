/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:58:15 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/01 14:39:18 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_swap(t_stack *stack)
{
    int tmp;

    if (stack->size < 1)
        return ;
    tmp = stack->array[0];
    stack->array[0] = stack->array[1];
    stack->array[1] = tmp;
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
// int main()
// {
//     t_stack *stack_a;
//     t_stack *stack_b;

//     stack_a = malloc(sizeof(t_stack));
//     stack_b = malloc(sizeof(t_stack));
//     stack_a->array = (int *)malloc(sizeof(int));
//     stack_b->array = (int *)malloc(sizeof(int));
//     stack_a->size = 4;
//     stack_b->size = 1;
//     stack_a->array[0] = 2;
//     stack_a->array[1] = 1;
//     stack_a->array[2] = 3;
//     stack_a->array[3] = 0;
//     ft_push(stack_a, stack_b);
//     int i = 0;
//     printf("-------- Stack A ----------\n");
//     while (i < stack_a->size)
//     {
//         printf("%d\n", stack_a->array[i]);
//         i++;
//     }
//     printf("-------- Stack B ----------\n");
//     printf("%d", stack_b->array[0]);
// }