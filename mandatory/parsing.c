/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:33:04 by ababdoul          #+#    #+#             */
/*   Updated: 2024/12/28 12:04:10 by ababdoul         ###   ########.fr       */
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

    i = 1;
    while (i < size - 1)
    {
        j = i + 1;
        while (j <= size - 1)
        {
            if (ft_strcmp(av[i], av[j + 1]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
