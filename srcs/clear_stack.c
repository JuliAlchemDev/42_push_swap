/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:36:19 by aserio            #+#    #+#             */
/*   Updated: 2026/07/27 14:42:38 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	clear_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->data);
		free(stack);
	}
}

static void	clear_ops(t_op_prop *ops)
{
	t_op	op;

	op = 0;
	while (op < OP_COUNT)
	{
		free(ops[op].name);
		op++;
	}
	free(ops);
}

void	clear_context(t_context *ctx)
{
	if (ctx->a)
		clear_stack(ctx->a);
	if (ctx->b)
		clear_stack(ctx->b);
	if (ctx->ops)
		clear_ops(ctx->ops);
	free(ctx);
}
