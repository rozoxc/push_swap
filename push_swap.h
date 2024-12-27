/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:39:05 by ababdoul          #+#    #+#             */
/*   Updated: 2024/12/24 21:46:07 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_stack{
    int *array;
    int size;
    int top;
}t_stack;

//operations functions
void ft_swap(t_stack *stack);// SA && SB
void ft_push(t_stack *src, t_stack *dest);// PA && PB
void ft_rotate(t_stack *stack);// ra && rb // the first element becomme the last one
void ft_reverse_rotate(t_stack *stack);// rra && rrb // the last becomme the first one

//utils functions
int	ft_atoi(const char *str);
int ft_is_digit(char *str);
int ft_strcmp(char *s1, char *s2);

#endif