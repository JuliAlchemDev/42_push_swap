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

static void	ft_putstrategy(t_context *ctx){
	if (ft_strcmp(ctx->strategy, "--simple") == 0)
		ft_putendl_fd("[bench] strategy: Simple / O(n)", 2);
	else if (ft_strcmp(ctx->strategy, "--medium") == 0)
		ft_putendl_fd("[bench] strategy: Intermediate / O(n√n)", 2);
	else if (ft_strcmp(ctx->strategy, "--complex") == 0)
		ft_putendl_fd("[bench] strategy: Complex / O(n log n)", 2);
	else
	{
		ft_putstr_fd("[bench] strategy: Adaptive /", 2);
		if (ctx->disorder < 0.2)
			ft_putendl_fd(" O(n)",2);
		else if (ctx->disorder >= 0.2 && ctx->disorder < 0.5)
			ft_putendl_fd(" O(n√n)",2);
		else if (ctx->disorder >= 0.5)
			ft_putendl_fd(" O(n log n)",2);
	}
}

void	ft_putbench(t_context *ctx)
{
	char str_total_ops;
	str_total_ops = ft_itoa(ctx->total_ops);

	ft_putdisorder(ctx->disorder);
	ft_putstrategy(ctx);

	// count_total(ctx);
	// ft_putstr_fd("[bench] total_ops: ", 2);
	// ft_putendl_fd(str_total_ops, 2);
	// free(str_total_ops);

	// ft_printf("[bench] sa: %d sb: %d ss: %d", ctx->sa, ctx->sb, ctx->ss);
	// ft_printf(" pa: %d pb: %d\n", ctx->pa, ctx->pb);
	// ft_printf("[bench] ra: %d rb: %d rr: %d", ctx->ra, ctx->rb, ctx->rr);
	// ft_printf(" rra: %d rrb: %d rrr: %d\n", ctx->rra, ctx->rrb, ctx->rrr);
}
