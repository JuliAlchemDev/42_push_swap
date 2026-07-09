/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:46:29 by aserio            #+#    #+#             */
/*   Updated: 2026/07/09 15:08:09 by aserio           ###   ########.fr       */
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

void	ra(t_context *ctx)
{
	rotate(ctx->a);
	ctx->ra++;
	ft_putendl_fd("ra", 1);
}

void	rb(t_context *ctx)
{
	rotate(ctx->b);
	ctx->rb++;
	ft_putendl_fd("rb", 1);
}

void	rr(t_context *ctx)
{
	rotate(ctx->a);
	rotate(ctx->b);
	ctx->rr++;
	ft_putendl_fd("rr", 1);
}
