/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:22:54 by aserio            #+#    #+#             */
/*   Updated: 2026/07/27 20:45:18 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_a_three(t_context *ctx)
{
	if (ctx->a->size != 3)
		return ;
	while (1)
	{
		if ((ctx->a->data[0] < ctx->a->data[1])
			&& (ctx->a->data[1] < ctx->a->data[2]))
			return ;
		if (ctx->a->data[0] < ctx->a->data[1])
			op(OP_RRA, ctx);
		if (ctx->a->data[0] > ctx->a->data[2])
			op(OP_RA, ctx);
		if (ctx->a->data[0] > ctx->a->data[1])
			op(OP_SA, ctx);
	}
}

static void	sort_a_two(t_context *ctx)
{
	if (ctx->a->size != 2)
		return ;
	if (ctx->a->data[0] > ctx->a->data[1])
		op(OP_SA, ctx);
}

void	sort_a_simple(t_context *ctx)
{
	sort_a_three(ctx);
	sort_a_two(ctx);
}