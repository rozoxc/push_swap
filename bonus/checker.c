/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:25:05 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/14 19:36:32 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_init_stacks(t_stack **stack_a, t_stack **stack_b, int size)
{
	*stack_a = (t_stack *)malloc(sizeof(t_stack));
	*stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	(*stack_a)->size = size;
	(*stack_a)->index_stack = 0;
	(*stack_b)->size = 0;
	(*stack_b)->index_stack = 1;
	(*stack_a)->array = (int *)malloc(sizeof(int) * (*stack_a)->size);
	(*stack_b)->array = (int *)malloc(sizeof(int) * size);
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

void	ft_fill_stack(t_stack *stack_a, char **av, int size)
{
	int		i;
	int		j;
	char	**split;
	int		index;

	i = 1;
	index = 0;
	while (i < size)
	{
		j = 0;
		split = ft_split(av[i], ' ');
		while (split[j] != NULL)
		{
			stack_a->array[index] = ft_atoi(split[j]);
			free(split[j]);
			index++;
			j++;
		}
		free(split);
		i++;
	}
}
void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int size;

    if (ac <= 1)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    size = ft_count_numbers(av, ac);
    ft_init_stacks(&stack_a, &stack_b, size);
    if (!ft_hundle_error(av, ac) || !ft_max(av, ac))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    ft_fill_stack(stack_a, av, ac);
    if (!ft_is_duplicate(stack_a, size))
    {
        free_stacks(stack_a, stack_b);
        write(2, "Error\n", 6);
        return (1);
    }
    read_and_execute(stack_a, stack_b);
    free_stacks(stack_a, stack_b);
    return (0);
}

