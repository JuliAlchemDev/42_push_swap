#include <stdio.h>

// Print initial stack_a, apply swap and print result

void swap(int stack[])
{
	int temp;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}
/*
int	main(void){
	int stack_a[] = {2, 1, 3, 6, 5, 8};
	int size = 6;
	int i;

	i = 0;
	printf("Init a and b:\n");
	while (i < size)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	printf("- -\n");
	printf("a b\n");

	swap(stack_a);

	i = 0;
	while (i < size)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	printf("- -\n");
	printf("a b\n");
	return (0);
}
*/

// Replace hardcoded stack_a with argv input, print results

#include <stdlib.h>

int main(int argc, char **argv)
{
	int *stack_a;
	int size_a;
	int i;

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

/******************** EXEC SWAP A *******************/

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
	}
	return (0);
}




