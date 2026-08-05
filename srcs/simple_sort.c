/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:22:54 by aserio            #+#    #+#             */
/*   Updated: 2026/08/05 14:23:28 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_a_two(t_context *ctx)
{
	if (ctx->a->size != 2)
		return ;
	if (ctx->a->data[0] > ctx->a->data[1])
		op(OP_SA, ctx);
}

static void	sort_a_three(t_context *ctx)
{
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

static void	sort_a_four(t_context *ctx)
{
	int		min;
	int		max;
	size_t	i_min;
	size_t	i_max;
	size_t	i;

	min = ctx->a->data[0];
	max = ctx->a->data[0];
	i_max = 0;
	i_min = 0;
	i = 0;
	while (i < 4)
	{
		if (min > ctx->a->data[i])
		{
			min = ctx->a->data[i];
			i_min = i;
		}
		if (max < ctx->a->data[i])
		{
			max = ctx->a->data[i];
			i_max = i;
		}
		i++;
	}
	if (i_min == 3)
		op(OP_RRA, ctx);
	else if (i_min == 1)
		op(OP_RA, ctx);
	else if (i_min == 2)
	{
		if (i_max == 3)
			op(OP_RRA, ctx);
		else if (i_max == 1)
			op(OP_RA, ctx);
	}
	op(OP_PB, ctx);
	sort_a_three(ctx);
	op(OP_PA, ctx);
	if (i_min == 2)
		op(OP_RA, ctx);
}

void	sort_a_small(t_context *ctx)
{
	if (ctx->a->size == 4)
		return (sort_a_four(ctx));
	if (ctx->a->size == 3)
		return (sort_a_three(ctx));
	if (ctx->a->size == 2)
		return (sort_a_two(ctx));
}
