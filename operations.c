#include "push_swap.h"

void	swap(t_stack *stack)
{
	int temp;
	temp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = temp;
}

void sa(t_stack *a)
{
	swap(a);
}
void sb(t_stack *b)
{
	swap(b);
}
void ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	push(t_stack *stack_in, t_stack *stack_out)
{
    int	i;

    if (stack_out->size == 0)
        return ;
    i = stack_in->size;
    while (i > 0)
    {
        stack_in->data[i] = stack_in->data[i - 1];
        i--;
    }
    stack_in->data[0] = stack_out->data[0];
    i = 0;
    while (i < stack_out->size - 1)
    {
        stack_out->data[i] = stack_out->data[i + 1];
        i++;
    }
    (stack_in->size)++;
    (stack_out->size)--;
}

void pa(t_stack *a, t_stack *b)
{
	push(a, b);
}
void pb(t_stack *b, t_stack *a)
{
	push(b, a);
}

void	rotate(t_stack *stack)
{
	int temp;
	int i;
	int size;

	size = stack->size;
	temp = stack->data[0];
	i = 0;
	while(i < size - 1)
	{
		stack->data[i] = stack->data[i+1];
		i++;
	}
	stack->data[size - 1] = temp;
}

void ra(t_stack *a)
{
	rotate(a);
}
void rb(t_stack *b)
{
	rotate(b);
}
void rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}


void	rvs_rotate(t_stack *stack)
{
	int temp;
	int i;
	int size;

	size = stack->size;
	temp = stack->data[size-1];
	i = size - 1;
	while(i > 0)
	{
		stack->data[i] = stack->data[i-1];
		i--;
	}
	stack->data[0] = temp;
}

void rra(t_stack *a)
{
	rvs_rotate(a);
}
void rrb(t_stack *b)
{
	rvs_rotate(b);
}
void rrr(t_stack *a, t_stack *b)
{
	rvs_rotate(a);
	rvs_rotate(b);
}
