/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:46:29 by aserio            #+#    #+#             */
/*   Updated: 2026/07/03 16:41:24 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rvs_rotate(t_stack *stack)
{
	int	temp;
	int	i;
	int	size;

	size = stack->size;
	temp = stack->data[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = temp;
}

int	rra(t_stack *a)
{
	rvs_rotate(a);
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_stack *b)
{
	rvs_rotate(b);
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	rvs_rotate(a);
	rvs_rotate(b);
	ft_putendl_fd("rrr", 1);
	return (1);
}
