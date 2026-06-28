#include <stdio.h>
#include <stdlib.h>

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

void rotate(int *stack, int size)
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


// int stack_a[] = {2, 1, 3, 6, 5, 8};

int main(int argc, char **argv)
{
	int *stack_a;
	int *stack_b;
	int size_a;
	int size_b;
	int i;

	size_b = 0;
	i = 0;
	if (argc > 1)
	{
		size_a = argc - 1;
		stack_a = (int *)malloc(size_a * sizeof(int));
		if (!stack_a)
			return (1);
		else
		{
			printf("Init a and b:\n");
			while(i < size_a)
			{
				stack_a[i] = atoi(argv[i+1]);
				printf("%d\n", stack_a[i]);
				i++;
			}

		}

		printf("_ _\n");
		printf("a b\n");

// ******************** EXEC SWAP A *******************

		printf("Exec sa:\n");
		swap(stack_a);
		i = 0;

		while (i < size_a)
		{
			printf("%d\n", stack_a[i]);
			i++;
		}
		printf("_ _\n");
		printf("a b\n");


// ******************** EXEC PUSH B *3 *******************
		stack_b = (int *)malloc(size_a * sizeof(int));
		printf("Exec pb pb pb:\n");
		push(stack_b, stack_a, &size_b, &size_a);
		push(stack_b, stack_a, &size_b, &size_a);
		push(stack_b, stack_a, &size_b, &size_a);

		i = 0;

		while (i < size_a) // ⚠️ Caution ⚠️
		{
			printf("%d %d\n", stack_a[i], stack_b[i]);
			i++;
		}
		printf("_ _\n");
		printf("a b\n");

	// ******************** EXEC ROTATE *******************
	printf("Exec ra rb (equiv. to rr):\n");
	// rotate(stack_a, 3);
	// rotate(stack_b, 3);
	rrotate(stack_a, 3, stack_b, 3);
	i = 0;
	while (i < 3)
		{
			printf("%d %d\n", stack_a[i], stack_b[i]);
			i++;
		}
	printf("_ _\n");
	printf("a b\n");

	// ******************** EXEC REVERSE ROTATE *******************
	printf("Exec rra rrb (equiv. to rrr):\n");
	// rvs_rotate(stack_a, 3);
	// rvs_rotate(stack_b, 3);
	rrvs_rotate(stack_a, 3, stack_b, 3);
	i = 0;
	while (i < 3)
		{
			printf("%d %d\n", stack_a[i], stack_b[i]);
			i++;
		}
	printf("_ _\n");
	printf("a b\n");

	// ******************** EXEC SWAP A *******************
	printf("Exec sa:\n");
	swap(stack_a);
		i = 0;
		while (i < size_a)
		{
			printf("%d %d\n", stack_a[i], stack_b[i]);
			i++;
		}
		printf("_ _\n");
		printf("a b\n");

	// ******************** EXEC PUSH A *3 *******************
	printf("Exec pa pa pa:\n");
	push(stack_a, stack_b, &size_a, &size_b);
	push(stack_a, stack_b, &size_a, &size_b);
	push(stack_a, stack_b, &size_a, &size_b);
	i = 0;
	while (i < size_a)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	printf("_ _\n");
	printf("a b\n");
	}
	return (0);
}

// gcc -Wall -Wextra -Werror playground.c -o test && ./test 2 1 3 6 5 8
