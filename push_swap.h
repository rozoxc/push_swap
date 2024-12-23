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
void parse_input(int ac, char **av);

void ft_swap(t_stack *stack);// SA && SB
void ft_push(t_stack *stack);// PA && PB
void ft_rotate(t_stack *stack);// ra && rb
void ft_reverse_rotate(t_stack *stack);// rra && rrb 
int	ft_atoi(const char *str);


int				ft_putchar(int c);
int				ft_putnbr(int nb);
int				ft_putstr(char *str);
int				ft_printf(const char *s, ...);
size_t			ft_strlen(const char *s);
int				convert_hex(unsigned int n);
int				print_addr(unsigned long num);
int				ft_convert_hex(unsigned int n);
unsigned int	ft_unsigned(unsigned int nb);
int ft_is_digit(char *str);
int ft_strcmp(char *s1, char *s2);

#endif