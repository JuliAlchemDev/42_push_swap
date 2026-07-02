/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:16:27 by aserio            #+#    #+#             */
/*   Updated: 2026/06/29 15:58:06 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
 * push the node n to the stack s
 */
static void	push(t_stack *stack_in, t_stack *stack_out)
{
	size_t	i;

	if (stack_out->size == 0)
		return ;
	i = stack_in->size;
	while (i > 0)
	{
		stack_in->data[i] = stack_in->data[i - 1];
		i--;
	}
	stack_in->data[0] = stack_out->data[0];
	i = 0;
	while (i < stack_out->size - 1)
	{
		stack_out->data[i] = stack_out->data[i + 1];
		i++;
	}
	(stack_in->size)++;
	(stack_out->size)--;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *b, t_stack *a)
{
	push(b, a);
	ft_putendl_fd("pb", 1);
}
