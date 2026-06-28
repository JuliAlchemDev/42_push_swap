# include <stdio.h>

// gcc -Wall -Wextra -Werror playground.c -o test && ./test
typedef struct s_stack {
    int *data;
    int size;
} t_stack;

float compute_disorder(t_stack *stack)
{
	int mistakes;
	int total_pairs;
	int i;
	int j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			total_pairs++;
			if(stack->data[i] > stack->data[j])
/*
i=0 (4):   4>67? no | 4>3? sí | 4>87? no | 4>23? no  → 1 mistake
i=1 (67):  67>3? sí | 67>87? no | 67>23? sí           → 2 mistakes
i=2 (3):   3>87? no | 3>23? no                        → 0 mistakes
i=3 (87):  87>23? sí                                   → 1 mistake
*/
				mistakes++;
			j++;
		}
		i++;
	}
	printf("Mistakes: %d\n", mistakes);
	printf("Total paires: %d\n", total_pairs);
	return ((float)mistakes / total_pairs);
}

int main(void)
{
	t_stack a;
	int data[] = {4, 67, 3, 87, 23};  // 0.40%
	// int data[] = {2, 1, 3, 6, 5, 8}; // 0.20%
	a.data = data;
	a.size = 5;
	float disorder;
	disorder = compute_disorder(&a);
	printf("disorder: %.2f%%\n", disorder);
}
