#include <stdio.h>

// Print initial stack_a, apply swap_a and print result

void swap(int stack[])
{
	int temp;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

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





