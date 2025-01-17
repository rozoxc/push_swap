/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:34:26 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/16 16:54:06 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_digit(char *str)
{
	int	i;
	int	found_digit;

	i = 0;
	found_digit = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!str[i] || str[i] < '0' || str[i] > '9')
			return (0);
		found_digit = 1;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	return (found_digit);
}
