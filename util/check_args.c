/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:41:39 by ababdoul          #+#    #+#             */
/*   Updated: 2024/12/29 20:42:06 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_arg(char *str)
{
    int i_space;
    int i_number;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            i_space++;
        else if(str[i] != ' ')
            i_number++;
        i++;    
    }
    if (is_space == 0)
        return (0);
    return (1);
}