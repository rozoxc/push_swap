/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:44:06 by ababdoul          #+#    #+#             */
/*   Updated: 2024/12/31 14:36:52 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort(t_stack *stack_a , t_stack *stack_b)
{
    (void)stack_b;
    if (stack_a->size > 2)
        return ;
    if (stack_a->size == 2)
    {
        if (stack_a->array[0] > stack_a->array[1])
            ft_swap(stack_a);
    }
}
