/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:33:04 by ababdoul          #+#    #+#             */
/*   Updated: 2024/12/28 10:39:05 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_hundle_error(char **av, int size)
{
    int i = 1;
    while (i < size)
    {
        if (ft_is_digit(av[i]) == 0 || ft_strcmp(av[i], av[i + 1]) == 0)
            return 0;
        else if (ft_atoi(av[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
