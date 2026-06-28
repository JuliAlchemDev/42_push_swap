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

void	rvs_rotate(int *stack, int size);
void	rrvs_rotate(int *stack_a, int size_a, int *stack_b, int size_b);

void	swap(t_stack *stack);
void	push(t_stack *stack_in, t_stack *stack_out);
void    rotate(t_stack *stack);

void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);

void pa(t_stack *a, t_stack *b);
void pb(t_stack *b, t_stack *a);

void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);

#endif

