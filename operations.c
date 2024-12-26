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

#include "push_swap.h"

void ft_swap(t_stack *stack)
{
    int tmp;

    if (stack_a->size < 1)
        return ;
    tmp = stack_a->array[0];
    stack_a->array[0] = stack_a->array[1];
    stack_a->array[1] = tmp;
}