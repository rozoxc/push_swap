/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:44:06 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/17 15:40:30 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->array[0] > stack->array[1])
	{
		if (stack->index_stack == 0)
			do_sa(stack);
		else
			do_sb(stack);
	}
}

void	sort_three(t_stack *stack)
{
	if (stack->array[0] > stack->array[1] && stack->array[0] > stack->array[2])
	{
		if (stack->index_stack == 0)
			do_ra(stack);
		else
			do_rb(stack);
	}
	if (stack->array[1] > stack->array[2] && stack->array[1] > stack->array[0])
	{
		if (stack->index_stack == 0)
			do_rra(stack);
		else
			do_rrb(stack);
	}
	if (stack->array[0] > stack->array[1])
	{
		if (stack->index_stack == 0)
			do_sa(stack);
		else
			do_sb(stack);
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_value;
	int	distance;

	if (is_sorted(stack_a) == 1)
		return ;
	min_value = get_min(stack_a);
	distance = get_distance(stack_a, min_value);
	if (distance == 1)
		do_ra(stack_a);
	else if (distance == 2)
	{
		do_ra(stack_a);
		do_ra(stack_a);
	}
	else if (distance == 3)
		do_rra(stack_a);
	if (is_sorted(stack_a) == 1)
		return ;
	do_pb(stack_a, stack_b);
	sort_three(stack_a);
	do_pa(stack_b, stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a));
	if (distance == 1)
		do_ra(stack_a);
	else if (distance == 2)
	{
		do_ra(stack_a);
		do_ra(stack_a);
	}
	else if (distance == 3)
	{
		do_rra(stack_a);
		do_rra(stack_a);
	}
	else if (distance == 4)
		do_rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	do_pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	do_pa(stack_b, stack_a);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else if (stack_a->size > 5)
		radix_sort(stack_a, stack_b);
}
