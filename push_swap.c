/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:09:30 by ababdoul          #+#    #+#             */
/*   Updated: 2024/12/24 21:58:47 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void print(t_stack *stack)
// {
//     int i;
    
//     i = 0;
//     while (i < stack->size - 1)
//     {
//         ft_printf("%d ", stack->array[i]);
//         i++;
//     }
// }
// void ft_operation(t_stack *stack)
// {
    
// }
int ft_hundle_error(char **av, int size)
{
    int i;

    i = 1;
    while (i < size)
    {
        if (ft_is_digit(av[i]) == 0 ||  ft_strcmp(av[i] , av[i + 1] ) == 0)
            return 0;
        i++;
    }
    return (1);
}

void ft_init_stacks(t_stack **stack_a, t_stack **stack_b, int size)
{
    *stack_a = (t_stack *)malloc(sizeof(t_stack));
    *stack_b = (t_stack *)malloc(sizeof(t_stack));
    if (*stack_a == NULL || *stack_b == NULL)
        return ;
    (*stack_a)->array = (int *)malloc(sizeof(int) * size);
    (*stack_b)->array = (int *)malloc(sizeof(int) * size);
    if ((*stack_a)->array == NULL || (*stack_b)->array == NULL)
    {
        free(*stack_a);
        free(*stack_b);
        *stack_a = NULL;
        *stack_b = NULL;
    }
}
void ft_fill_stack(t_stack *stack_a, char **av, int size)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < size)
    {
        stack_a->array[j] = ft_atoi(av[i]);
        i++;
        j++;
    }
}
int main(int ac , char **av)
{
    if (ac > 1)
    {
        t_stack *stack_a;
        t_stack *stack_b;

        stack_a = NULL;
        stack_b = NULL;
        stack_a->size = ac;
        ft_init_stacks(&stack_a, &stack_b, ac);
        if (ft_hundle_error(av, ac) == 0)
        {
            write(1, "Error", 5);
            free(stack_a);
            free(stack_b);
            free(stack_a->array);
            free(stack_b->array);
        }
        ft_fill_stack(stack_a , av, ac);
        free(stack_a);
        free(stack_b);
        free(stack_a->array);
        free(stack_b->array);
    }
    return 0;
}
