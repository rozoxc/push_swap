/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:39:05 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/03 13:22:41 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
 #define INT_MAX 2147483647
typedef struct s_stack{
    int *array;
    int size;
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
int ft_strlen(char *str);
int ft_count_numbers(char **av, int ac);
char	**ft_split(char  *s, char c);

//sorts functions
void sort(t_stack *stack_a , t_stack *stack_b);

//parsing functions
int ft_hundle_error(char **av, int size);
int ft_is_duplicate(t_stack *stack_a, int size);
int ft_check(char *str);
int ft_max(char **av, int size);
#endif