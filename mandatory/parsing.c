/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:33:04 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/14 17:19:16 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_hundle_error(char **av, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (ft_is_digit(av[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_duplicate(t_stack *stack_a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_a->array[i] == stack_a->array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check(char *str)
{
	if (ft_strlen(str) > 10)
		return (0);
	else if (ft_strlen(str) == 10)
	{
		if (ft_atoi(&str[9]) > 7)
			return (0);
	}
	return (1);
}

int	ft_max(char **av, int size)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < size)
	{
		j = 0;
		split = ft_split(av[i], ' ');
		while (split[j] != NULL)
		{
			if (ft_check(split[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
