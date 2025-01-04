/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:48:22 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/03 20:51:21 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int find_min_cost(t_stack *stack_a, t_stack *stack_b, int *cost_a, int *cost_b)
{
    int i;
    int min_cost;
    int current_cost_a;
    int current_cost_b;
    int best_index;
    int total_cost;

    min_cost = INT_MAX;
    best_index = 0;
    i = 0;
    while (i < stack_b->size)
    {
        current_cost_b = calculate_cost(stack_b, i);
        current_cost_a = find_target_cost(stack_a, stack_b->array[i]);
        total_cost = calculate_total_cost(current_cost_a, current_cost_b);
        if (total_cost < min_cost)
        {
            min_cost = total_cost;
            best_index = i;
            *cost_a = current_cost_a;
            *cost_b = current_cost_b;
        }
        i++;
    }
    return (best_index);
}
