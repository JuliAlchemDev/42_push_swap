#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// DELETE !
# include <stdio.h>
# include <stdlib.h>
// DELETE !

typedef struct s_stack {
    int *data;
    int size;
} t_stack;

// Operation functions

void	swap(int *stack);
void	s_swap(int *stack_a, int *stack_b);
void	push(int *stack_in, int *stack_out, int *size_in, int *size_out);
void    rotate(int *stack, int size);
void	rrotate(int *stack_a, int size_a, int *stack_b, int size_b);
void	rvs_rotate(int *stack, int size);
void	rrvs_rotate(int *stack_a, int size_a, int *stack_b, int size_b);

#endif
