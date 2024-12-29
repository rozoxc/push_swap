/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:33:04 by ababdoul          #+#    #+#             */
/*   Updated: 2024/12/29 11:24:14 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_hundle_error(char **av, int size)
{
    int i;

    i = 1;
    while (i < size)
    {
        if (ft_is_digit(av[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
int ft_is_duplicate(char **av , int size)
{
    int i;
    int j;
    int num1;
    int num2;

    i = 1;
    while (i < size - 1)
    {
        num1 = ft_atoi(av[i]);
        j = i + 1;
        while (j <= size - 1)
        {
            num2 = ft_atoi(av[j]);
            if (num1 == num2)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int ft_max(char **av, int size)
{
    int i;

    i = 1;
    while (i < size)
    {
        if (ft_strlen(av[i]) > 10)
            return (0);
        else if (ft_strlen(av[i]) == 10)
        {
            if (ft_atoi(&av[i][9]) > 7)
                return (0);
        }
        i++;
    }
    return (1);
}
