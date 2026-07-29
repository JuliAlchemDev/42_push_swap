#include "../include/push_swap.h"

t_stack	*get_stack(int size, char **nums)
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
