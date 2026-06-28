#include "push_swap.h"

// Initial stack_a = {2, 1, 3, 6, 5, 8};

// gcc -Wall -Wextra -Werror main.c operations.c -o test && ./test 2 1 3 6 5 8

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int i;

	b.size = 0;
	b.data = NULL;
	i = 0;
	if (argc > 1)
	{
		a.size = argc - 1;
		a.data = (int *)malloc(a.size * sizeof(int));
		if (!a.data)
			return (1);
		printf("Init a and b:\n");
		while(i < a.size)
		{
			a.data[i] = atoi(argv[i+1]);
			printf("%d\n", a.data[i]);
			i++;
		}
		printf("_ _\n");
		printf("a b\n");

		// ******************** EXEC SWAP A *******************

		printf("Exec sa:\n");
		sa(&a);
		i = 0;

		while (i < a.size)
		{
			printf("%d\n", a.data[i]);
			i++;
		}
		printf("_ _\n");
		printf("a b\n");
	}
/*


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
*/
	return (0);
}


