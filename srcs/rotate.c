/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:46:29 by aserio            #+#    #+#             */
/*   Updated: 2026/06/29 14:46:31 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack *stack)
{
	int	temp;
	int	i;
	int	size;

	size = stack->size;
	temp = stack->data[0];
	i = 0;
	while (i < size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[size - 1] = temp;
}

void	ra(t_stack *a)
{
	rotate(a);
}

void	rb(t_stack *b)
{
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}
