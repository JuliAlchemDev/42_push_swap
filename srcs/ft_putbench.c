/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:03:20 by aserio            #+#    #+#             */
/*   Updated: 2026/07/20 17:42:37 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	count_total(t_context *ctx)
{
	ctx->total_ops += ctx->sa;
	ctx->total_ops += ctx->sb;
	ctx->total_ops += ctx->ss;
	ctx->total_ops += ctx->pa;
	ctx->total_ops += ctx->pb;
	ctx->total_ops += ctx->ra;
	ctx->total_ops += ctx->rb;
	ctx->total_ops += ctx->rr;
	ctx->total_ops += ctx->rra;
	ctx->total_ops += ctx->rrb;
	ctx->total_ops += ctx->rrr;
}

void	ft_putbench(t_context *ctx)
{
	ft_putdisorder(ctx->disorder);
	if (ft_strcmp(ctx->strategy, "--simple") == 0)
		ft_printf("[bench] strategy: Simple / O(n√n)\n");
	else if (ft_strcmp(ctx->strategy, "--medium") == 0)
		ft_printf("[bench] strategy: Intermediate / O(n√n)\n");
	else if (ft_strcmp(ctx->strategy, "--complex") == 0)
		ft_printf("[bench] strategy: Complex / O(n log n)\n");
	else
		ft_printf("[bench] strategy: Adaptive / O(n√n)\n", ctx->strategy);
	count_total(ctx);
	ft_printf("[bench] total_ops: %d\n", ctx->total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d", ctx->sa, ctx->sb, ctx->ss);
	ft_printf(" pa: %d pb: %d\n", ctx->pa, ctx->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d", ctx->ra, ctx->rb, ctx->rr);
	ft_printf(" rra: %d rrb: %d rrr: %d\n", ctx->rra, ctx->rrb, ctx->rrr);
}
