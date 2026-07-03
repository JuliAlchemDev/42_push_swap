/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:16:15 by aserio            #+#    #+#             */
/*   Updated: 2026/07/03 16:40:39 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_stack(size_t size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = ft_calloc(sizeof(int), size);
	if (!(stack->data))
	{
		free(stack);
		error();
	}
	stack->size = 0;
	return (stack);
}

int	is_duplicated(char num[], int *data, size_t size)
{
	size_t	i;
	int		n;

	n = ft_atoi(num);
	if (size > 0)
	{
		i = 0;
		while ((i < size - 1) && (n != data[i]))
			i++;
		return (n == data[i]);
	}
	return (0);
}

t_stack	*load_stack(size_t size, char *nums[])
{
	t_stack	*stack;
	size_t	i;

	stack = create_stack(size);
	i = 0;
	if (nums)
	{
		while (i < size)
		{
			if (!is_valid_int(nums[i])
				|| is_duplicated(nums[i], stack->data, i))
			{
				clear_stack(stack);
				error();
			}
			stack->data[i] = ft_atoi(nums[i]);
			i++;
		}
		stack->size = i;
	}
	return (stack);
}
