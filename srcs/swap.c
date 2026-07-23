/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:59:01 by aserio            #+#    #+#             */
/*   Updated: 2026/07/09 15:10:01 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->data[0];
		stack->data[0] = stack->data[1];
		stack->data[1] = temp;
	}
}

void	sa(t_context *ctx)
{
	swap(ctx->a);
	ctx->ops[OP_SA]++;
	ft_putendl_fd("sa", 1);
}

void	sb(t_context *ctx)
{
	swap(ctx->b);
	ctx->ops[OP_SB]++;
	ft_putendl_fd("sb", 1);
}

void	ss(t_context *ctx)
{
	swap(ctx->a);
	swap(ctx->b);
	ctx->ops[OP_SS]++;
	ft_putendl_fd("ss", 1);
}
