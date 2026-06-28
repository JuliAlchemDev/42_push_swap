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

void	swap(t_stack *stack);
void	push(t_stack *stack_in, t_stack *stack_out);
void    rotate(t_stack *stack);
void	rvs_rotate(t_stack *stack);

void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);

void pa(t_stack *a, t_stack *b);
void pb(t_stack *b, t_stack *a);

void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);

void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

#endif

