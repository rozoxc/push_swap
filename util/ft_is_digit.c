/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozox <rozox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:34:26 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/05 14:05:07 by rozox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_is_digit(char *str)
{
    int i;
    int found_digit;
    
    i = 0;
    found_digit = 0;
    while (str[i] != '\0')
    {
        while (str[i] == ' ')
            i++;
        if (!str[i])
            break;
        if (str[i] == '-' || str[i] == '+')
            i++;
        if (!str[i])
            return (0);
        if (str[i] < '0' || str[i] > '9')
            return (0);
        found_digit = 1;
        while (str[i] && str[i] >= '0' && str[i] <= '9')
        {
            if (str[i + 1] == '-' || str[i + 1] == '+')
                return (0);
            i++;
        }
    }
    return found_digit;
}

