/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozox <rozox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:00:18 by rozox             #+#    #+#             */
/*   Updated: 2025/01/09 14:19:26 by rozox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack *src, t_stack *dest)
{
	int	i;

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

void do_pa(t_stack *stack_b, t_stack *stack_a)
{
    ft_push(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void do_pb(t_stack *stack_a, t_stack *stack_b)
{
    ft_push(stack_a, stack_b);
    write(1, "pb\n", 3);
}