/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:57:13 by ababdoul          #+#    #+#             */
/*   Updated: 2024/12/22 20:58:30 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	return (i);
}

static int	signe_char(char c)
{
	if (c == '-')
	{
		return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				signe;
	long			result;

	i = spaces(str);
	result = 0;
	signe = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		signe = signe_char(str[i++]);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 922337203685477580
			|| (result == 922337203685477580 && (str[i] - '0') > 7))
		{
			if (signe == 1)
				return (-1);
			else
				return (0);
		}
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * signe);
}