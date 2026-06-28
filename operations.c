#include "push_swap.h"

void	swap(int stack[])
{
	int temp;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	s_swap(int *stack_a, int *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(int *stack_in, int *stack_out, int *size_in, int *size_out)
{
    int	i;

    if (*size_out == 0)
        return ;
    i = *size_in;
    while (i > 0)
    {
        stack_in[i] = stack_in[i - 1];
        i--;
    }
    stack_in[0] = stack_out[0];
    i = 0;
    while (i < *size_out - 1)
    {
        stack_out[i] = stack_out[i + 1];
        i++;
    }
    (*size_in)++;
    (*size_out)--;
}

void	rotate(int *stack, int size)
{
	int temp;
	int i;
	temp = stack[0];
	i = 0;
	while(i < size - 1)
	{
		stack[i] = stack[i+1];
		i++;
	}
	stack[size - 1] = temp;
}

void	rrotate(int *stack_a, int size_a, int *stack_b, int size_b)
{
	rotate(stack_a, size_a);
	rotate(stack_b, size_b);
}

void	rvs_rotate(int *stack, int size)
{
	int temp;
	int i;
	temp = stack[size-1];
	i = size - 1;
	while(i > 0)
	{
		stack[i] = stack[i-1];
		i--;
	}
	stack[0] = temp;
}
void	rrvs_rotate(int *stack_a, int size_a, int *stack_b, int size_b)
{
	rvs_rotate(stack_a, size_a);
	rvs_rotate(stack_b, size_b);
}
