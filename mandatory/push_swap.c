/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:09:30 by ababdoul          #+#    #+#             */
/*   Updated: 2024/12/30 21:32:03 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void f()
{
    system("leaks push_swap");
}
void print(t_stack *stack)
{
    int i = 0;
    // printf("size = %d\n", stack->size);
    while (i < stack->size)
    {
        printf("%d ", stack->array[i]);
        i++;
    }
    printf("\n"); 
}

void ft_init_stacks(t_stack **stack_a, t_stack **stack_b, int size)
{
    *stack_a = (t_stack *)malloc(sizeof(t_stack));
    *stack_b = (t_stack *)malloc(sizeof(t_stack));
    if (*stack_a == NULL || *stack_b == NULL)
        return;
    (*stack_a)->size = size;
    (*stack_b)->size = 0;

    // printf("size int init :  %d \n" ,(*stack_a)->size);
    (*stack_a)->array = (int *)malloc(sizeof(int) * (size - 1));
    (*stack_b)->array = (int *)malloc(sizeof(int) * (size - 1));

    if ((*stack_a)->array == NULL || (*stack_b)->array == NULL)
    {
        free((*stack_a)->array);
        free((*stack_b)->array);
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
    char **split;
    int index;

    i = 1;
    index = 0;
    while (i < size)
    {
        j = 0;
        split = ft_split(av[i], ' ');
        while (split[j] != NULL)
        {
            stack_a->array[index] = ft_atoi(split[j]);
            // printf("%d \n", stack_a->array[index]);
            free(split[j]);
            index++;
            j++;
        }
        free(split);
        i++;
    }
}

void free_stacks(t_stack *stack_a, t_stack *stack_b)
{
    free(stack_a->array);
    free(stack_a);
    free(stack_b->array);
    free(stack_b);
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        t_stack *stack_a;
        t_stack *stack_b;
        int size;

        stack_a = NULL;
        stack_b = NULL;
        size = ft_count_numbers(av, ac);
        // printf("new size = %d\n", size);
        ft_init_stacks(&stack_a, &stack_b, size);
        if (!stack_a || !stack_b)
            free_stacks(stack_a, stack_b);
        if (!ft_is_duplicate(av, ac) || !ft_max(av, ac))
        {
            write(1, "Error\n", 6);
            return 1;
        }
        ft_fill_stack(stack_a, av, ac);
        sort(stack_a , stack_b);
        print(stack_a);
        free_stacks(stack_a, stack_b);
    }
    return 0;
}
