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
void insertion_sort(t_stack *a)
{
	t_stack *b;
	b = create_stack(a->size);
	// pa(b, a);
	printf("%d", b->data[0]);
	free(b);
}

#ifdef TEST

/*

gcc -DTEST srcs/insertion_sort.c srcs/push.c srcs/load_stack.c srcs/clear_stack.c srcs/is_valid_int.c srcs/error.c srcs/ft_strcmp.c utils/display_stacks.c utils/putstack.c -L./Libft -lft -I./include -o test

*/

int main(void)
{
	t_stack *a;
	char *nums[] = {"1", "4", "7", "5", "2", NULL};

	a = get_stack(5, nums);
	insertion_sort(a);
	clear_stack(a);
	return (0);
}

#endif
