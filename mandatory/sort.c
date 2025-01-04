/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:44:06 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/03 20:49:04 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"


int ft_chunck_size(int size)
{
    if (size >= 100)
        return (20);
    else if(size >= 500)
        return (50);
    else
        return (size / 10);
}
void push_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int current_chunk, int chunk_size)
{
    int i;

    i = 0;
    while (i < chunk_size && stack_a->size > 0)
    {
        if (belongs_to_chunk(stack_a->array[0], current_chunk, chunk_size))
        {
            ft_push(stack_a, stack_b);
            write(1, "pb\n", 3);
        }
        else
        {
            ft_rotate(stack_a);
            write(1, "ra\n", 3);
        }
        i++;
    }
}
void sort_and_merge_back(t_stack *stack_a, t_stack *stack_b)
{
    int cost_a;
    int cost_b;

    while (stack_b->size > 0)
    {
        find_min_cost(stack_b, &cost_a, &cost_b);
        execute_best_move(stack_a, stack_b, cost_a, cost_b);
        ft_push(stack_b, stack_a);
        write(1, "pa\n", 3);
    }
}
void execute_best_move(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b)
{
    while (cost_a > 0 || cost_b > 0)
    {
        if (cost_a > 0 && cost_b > 0)
        {
            ft_rotate_both(stack_a, stack_b);
            write(1, "rr\n", 3);
            cost_a--;
            cost_b--;
        }
        else if (cost_a > 0)
        {
            ft_rotate(stack_a);
            write(1, "ra\n", 3);
            cost_a--;
        }
        else if (cost_b > 0)
        {
            ft_rotate(stack_b);
            write(1, "rb\n", 3);
            cost_b--;
        }
    }
}

void sort(t_stack *stack_a , t_stack *stack_b)
{
    int chunck_size;
    int chunck;
    int current_chunck;

    chunck_size = ft_chunck_size(stack_a->size);
    chunck = stack_a->size / chunck_size;
    current_chunck = 0;
    while (current_chunck < chunck)
    {
        push_chunk_to_b(stack_a, stack_b, current_chunck, chunck);
        current_chunck++;
    }
    sort_and_merge_back(stack_a, stack_b);
}