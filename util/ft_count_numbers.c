/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:14:10 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/14 14:24:16 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_count_numbers(char **av, int ac)
{
	int		i;
	int		count;
	int		j;
	char	**split;

	i = 1;
	count = 0;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j] != NULL)
		{
			count++;
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (count);
}
