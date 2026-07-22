/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 11:02:52 by aserio            #+#    #+#             */
/*   Updated: 2026/07/22 21:45:27 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	adaptive_strategy(t_context *ctx)
{
	if (ctx->disorder < 0.2)
		insertion_sort(ctx);
	else if (ctx->disorder >= 0.2 && ctx->disorder < 0.5)
		chunk_sort(ctx);
	else if (ctx->disorder >= 0.5)
		quick_sort(ctx);
}

void	select_sort(t_context *ctx)
{
	if (ft_strcmp(ctx->strategy, "--simple") == 0)
		insertion_sort(ctx);
	else if (ft_strcmp(ctx->strategy, "--medium") == 0)
		chunk_sort(ctx);
	else if (ft_strcmp(ctx->strategy, "--complex") == 0)
		quick_sort(ctx);
	else
		adaptive_strategy(ctx);
	if (ctx->bench_flag)
		ft_putbench(ctx);
}
