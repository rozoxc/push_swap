/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:52:21 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/13 17:03:48 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void normalize_numbers(t_stack *stack)
{
    int min;
    int i;

    min = get_min(stack);
    // If minimum is negative, add its absolute value to make all numbers positive
    if (min < 0)
    {
        i = 0;
        while (i < stack->size)
        {
            stack->array[i] += -min;
            i++;
        }
    }
}

// Count bits needed for the largest number
int get_max_bits(t_stack *stack)
{
    int max;
    int bits;
    int i;

    max = stack->array[0];
    i = 1;
    // Find maximum value
    while (i < stack->size)
    {
        if (stack->array[i] > max)
            max = stack->array[i];
        i++;
    }

    // Count bits
    bits = 0;
    while (max > 0)
    {
        max = max >> 1;
        bits++;
    }
    return (bits);
}

// Main radix sort function
void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int bits;      // Total bits to process
    int bit_pos;   // Current bit position
    int size;      // Original stack size
    int i;         // Counter for numbers

    // Make all numbers positive for bitwise operations
    normalize_numbers(stack_a);
    
    bits = get_max_bits(stack_a);
    size = stack_a->size;

    // Process each bit position
    bit_pos = 0;
    while (bit_pos < bits)
    {
        // Process each number
        i = 0;
        while (i < size)
        {
            // If current bit is 0, push to B
            if ((stack_a->array[0] >> bit_pos) & 1)
                do_ra(stack_a);
            else
                do_pb(stack_a, stack_b);
            i++;
        }
        
        // Move all numbers back to A
        while (stack_b->size > 0)
            do_pa(stack_b, stack_a);
            
        bit_pos++;
    }
}
