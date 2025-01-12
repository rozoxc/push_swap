/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozox <rozox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:05:28 by rozox             #+#    #+#             */
/*   Updated: 2025/01/09 17:46:29 by rozox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

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

void do_rra(t_stack *stack_a)
{
    ft_reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}

void    do_rrb(t_stack *stack_b)
{
    ft_reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
}
void do_rrr(t_stack *stack_a, t_stack *stack_b)
{
     ft_reverse_rotate(stack_a);
     ft_reverse_rotate(stack_b);
     write(1, "rrr\n", 4);    
}