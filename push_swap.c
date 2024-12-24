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
int main(int ac , char **av)
{
    if (ac > 1)
    {
        int i;
        int j;
        int flag;
        t_stack *stack;
        
        stack = (t_stack *)malloc(sizeof(t_stack));
        if (stack == NULL)
            return (1);
        stack->size = ac ;
        stack->array = (int *)malloc(sizeof(int) * stack->size);
        flag = 0;
        if (stack->array == NULL)
            return (100);
        i = 1;
        j = 0;
        while (i < stack->size)
        {
            if(ft_is_digit(av[i]) == 0 || ft_strcmp(av[i] , av[i - 1]) == 0)
            {
                ft_printf("Error");
                flag = 1;
                break;
            }
            stack->array[j] = ft_atoi(av[i]);
            i++;
            j++;
        }
        // ft_operation(stack);
    }
    return 0;
}
