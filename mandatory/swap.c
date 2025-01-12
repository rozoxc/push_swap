/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozox <rozox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:07:33 by rozox             #+#    #+#             */
/*   Updated: 2025/01/09 01:19:36 by rozox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 1)
		return ;
	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
}

void do_sa(t_stack *stack_a)
{
    ft_swap(stack_a);
    write(1, "sa\n", 3);
}

void do_sb(t_stack *stack_b)
{
    ft_swap(stack_b);
    write(1, "sb\n", 3);
}