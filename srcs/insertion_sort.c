#include "../include/push_swap.h"

void	insertion_sort(t_stack *a)
{
	t_stack	*b;
	size_t	count_rot;
	size_t	limit;

	// int temp;
	b = create_stack(a->size);
	while (a->size >= 1)
	{
		// temp = a-> data[0];
		count_rot = 0;
		limit = b->size;
// // ============================= Debug Traces =====================
		// printf("Stack A:");
		// for (size_t i = 0; i < a->size; i++)
		// 	printf(" %d", a->data[i]);
		// printf("\nStack B:");
		// for (size_t i = 0; i < b->size; i++)
		// 	printf(" %d", b->data[i]);
		// printf("\nTemp value: %d\n", temp);
// // ============================= Debug =====================
		while(a->data[0] < b->data[0] && count_rot < limit)
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
