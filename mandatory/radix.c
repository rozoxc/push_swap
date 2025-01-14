/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:52:21 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/14 13:58:25 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	normalize_numbers(t_stack *stack)
{
	int	min;
	int	i;

	min = get_min(stack);
	if (min < 0)
	{
		i = 0;
		while (i < stack->size)
		{
			stack->array[i] += -min;
			i++;
		}
	}
}

int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;
	int	i;

	max = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	bits = 0;
	while (max > 0)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	bits;
	int	bit_pos;
	int	size;
	int	i;

	normalize_numbers(stack_a);
	bits = get_max_bits(stack_a);
	size = stack_a->size;
	bit_pos = 0;
	while (bit_pos < bits)
	{
		i = 0;
		while (i < size)
		{
			if ((stack_a->array[0] >> bit_pos) & 1)
				do_ra(stack_a);
			else
				do_pb(stack_a, stack_b);
			i++;
		}
		while (stack_b->size > 0)
			do_pa(stack_b, stack_a);
		bit_pos++;
	}
}
