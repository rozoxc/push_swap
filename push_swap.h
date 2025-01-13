/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:39:05 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/13 16:55:52 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_stack{
    int *array;
    int size;
    int index;
    int index_stack;
}t_stack;

//operations functions
void ft_swap(t_stack *stack);// SA && SB
void ft_push(t_stack *src, t_stack *dest);// PA && PB
void ft_rotate(t_stack *stack);// ra && rb // the first element becomme the last one
void ft_reverse_rotate(t_stack *stack);// rra && rrb // the last becomme the first one
void do_pa(t_stack *stack_b, t_stack *stack_a);
void do_pb(t_stack *stack_a, t_stack *stack_b);
void do_rra(t_stack *stack_a);
void    do_rrb(t_stack *stack_b);
void do_rrr(t_stack *stack_a, t_stack *stack_b);
void do_ra(t_stack *stack_a);
void do_rb(t_stack *stack_b);
void do_sa(t_stack *stack_a);
void do_sb(t_stack *stack_b);

//utils functions
int	ft_atoi(const char *str);
int ft_is_digit(char *str);
int ft_strcmp(char *s1, char *s2);
int ft_strlen(char *str);
int ft_count_numbers(char **av, int ac);
char	**ft_split(char  *s, char c);

//sorts functions
void sort(t_stack *stack_a , t_stack *stack_b);
void radix_sort(t_stack *stack_a, t_stack *stack_b);
//sort helpers

int get_min(t_stack *stack);
int get_distance(t_stack *stack, int value);
int is_sorted(t_stack *stack);

//parsing functions
int ft_hundle_error(char **av, int size);
int ft_is_duplicate(t_stack *stack_a, int size);
int ft_check(char *str);
int ft_max(char **av, int size);
#endif