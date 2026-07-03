#include "../include/push_swap.h"

// For testing, delete when finish
static t_stack	*get_stack(int size, char **nums)
{
	t_stack	*stack;

	if (size == 1)
	{
		nums = ft_split(nums[0], ' ');
		while (nums[size])
			size++;
	}
	stack = load_stack(size, nums);
	if (!stack)
		return (NULL);
	return (stack);
}

// delete when finish

void	insertion_sort(t_stack *a)
{
	t_stack	*b;
	size_t	count_rot;
	size_t	limit;

	int temp;
	b = create_stack(a->size);
	while (a->size >= 1)
	{
		temp = a-> data[0];
		count_rot = 0;
		limit = b->size;
// ============================= Debug Traces =====================
		printf("Stack A:");
		for (int i = 0; i < a->size; i++)
			printf(" %d", a->data[i]);
		printf("\nStack B:");
		for (int i = 0; i < b->size; i++)
			printf(" %d", b->data[i]);
		printf("\nTemp value: %d\n", temp);
// ============================= Debug =====================
		while(b->size > 0 && a->data[0] < b->data[0] && count_rot < limit)
		{
			rb(b);
			count_rot++;
		}
		pb(b, a);
		while (count_rot > 0)
		{
			rrb(b);
			count_rot--;
		}

	}
	while(b->size > 0)
		pa(a, b);
	clear_stack(b);
}

#ifdef TEST

// gcc -DTEST $(ls srcs/*.c | grep -v main.c) utils/*.c -L./Libft -lft -I./include -o test

int main(void)
{
	t_stack *a;
	char *nums[] = {"2", "1", "3", "6", "5", "8", NULL};
	// char *nums[] = { "1", "2", "3", "5", "6", "8", NULL};
	a = get_stack(6, nums);
	insertion_sort(a);
	printf("\nFinal stack A:");
	for(int i = 0; i < a->size; i++)
		printf(" %d", a->data[i]);
	clear_stack(a);

	return (0);
}

#endif
