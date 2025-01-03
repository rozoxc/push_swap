/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:34:26 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/02 20:49:38 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_is_digit(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
        {
            i++;
            continue;
        }
        if (str[i] == '-' || str[i] == '+')
            i++;
        if (!str[i])
            return (0);
        if (str[i] < '0' || str[i] > '9') 
            return (0);
        while (str[i] && str[i] >= '0' && str[i] <= '9')
            i++;
    }
    return (1);
}
