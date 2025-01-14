/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:58:57 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/14 19:31:01 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int is_sorted(t_stack *stack)
{
    int i;

    i = 0;
    while (i < stack->size - 1)
    {
        if (stack->array[i] > stack->array[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int execute_operation(char *line, t_stack *stack_a, t_stack *stack_b)
{
    if (!ft_strcmp(line, "sa\n"))
        do_sa(stack_a);
    else if (!ft_strcmp(line, "sb\n"))
        do_sb(stack_b);
    else if (!ft_strcmp(line, "ss\n"))
        do_ss(stack_a, stack_b);
    else if (!ft_strcmp(line, "pa\n"))
        do_pa(stack_b, stack_a);
    else if (!ft_strcmp(line, "pb\n"))
        do_pb(stack_a, stack_b);
    else if (!ft_strcmp(line, "ra\n"))
        do_ra(stack_a);
    else if (!ft_strcmp(line, "rb\n"))
        do_rb(stack_b);
    else if (!ft_strcmp(line, "rr\n"))
        do_rr(stack_a, stack_b);
    else if (!ft_strcmp(line, "rra\n"))
        do_rra(stack_a);
    else if (!ft_strcmp(line, "rrb\n"))
        do_rrb(stack_b);
    else if (!ft_strcmp(line, "rrr\n"))
        do_rrr(stack_a, stack_b);
    else
        return (0);
    return (1);
}

void read_and_execute(t_stack *stack_a, t_stack *stack_b)
{
    char *line;

    while ((line = get_next_line(0)))
    {
        if (!execute_operation(line, stack_a, stack_b))
        {
            free(line);
            write(2, "Error\n", 6);
            return;
        }
        free(line);
    }
    
    if (is_sorted(stack_a) && stack_b->size == 0)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}