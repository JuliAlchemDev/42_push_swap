/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:03:20 by aserio            #+#    #+#             */
/*   Updated: 2026/07/26 11:11:48 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_putstrategy(t_context *ctx)
{
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
			ft_putendl_fd(" O(n)", 2);
		else if (ctx->disorder >= 0.2 && ctx->disorder < 0.5)
			ft_putendl_fd(" O(n√n)", 2);
		else if (ctx->disorder >= 0.5)
			ft_putendl_fd(" O(n log n)", 2);
	}
}

static void	ft_puttotal(t_context *ctx)
{
	char	*str_total_ops;

	ft_putstr_fd("[bench] total_ops: ", 2);
	str_total_ops = ft_itoa(ctx->total_ops);
	ft_putendl_fd(str_total_ops, 2);
	free(str_total_ops);
}

static void	put_op(char *name, int count)
{
	char	*str;

	str = ft_itoa(count);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(str, 2);
	free(str);
}

static void	ft_putops(t_context *ctx)
{
	ft_putstr_fd("[bench]", 2);
	put_op(" sa: ", ctx->ops[SA].count);
	put_op(" sb: ", ctx->ops[SB].count);
	put_op(" ss: ", ctx->ops[SS].count);
	put_op(" pa: ", ctx->ops[PA].count);
	put_op(" pb: ", ctx->ops[PB].count);
	ft_putendl_fd("", 2);
	ft_putstr_fd("[bench]", 2);
	put_op(" ra: ", ctx->ops[RA].count);
	put_op(" rb: ", ctx->ops[RB].count);
	put_op(" rr: ", ctx->ops[RR].count);
	put_op(" rra: ", ctx->ops[RRA].count);
	put_op(" rrb: ", ctx->ops[RRB].count);
	put_op(" rrr: ", ctx->ops[RRR].count);
	ft_putendl_fd("", 2);
}

void	ft_putbench(t_context *ctx)
{
	ft_putdisorder(ctx->disorder);
	ft_putstrategy(ctx);
	ft_puttotal(ctx);
	ft_putops(ctx);
}
