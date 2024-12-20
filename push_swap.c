/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:09:30 by ababdoul          #+#    #+#             */
/*   Updated: 2024/12/18 18:09:34 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac , char **av)
{
    int i;
    int j;

    if (ac >= 2)
    {
        i = 0;
        while (i < ac - 1)
        {
            j = 0;
            while (av[i][j] != '\0')
            {
                if (av[i][j] >= 'a' && av[i][j] <= 'z')
                {
                    printf("%s", "Error");
                    break;
                }
                j++;
            }
            i++;
        }
    }
    printf("\n");
    return (0);
}