/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 11:02:52 by aserio            #+#    #+#             */
/*   Updated: 2026/07/09 15:50:12 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	select_sort(t_context *ctx)
{
	ctx->disorder = compute_disorder(ctx->a);
	ctx->total_ops = 0;
	ctx->sa = 0;
	ctx->sb = 0;
	ctx->ss = 0;
	ctx->pa = 0;
	ctx->pb = 0;
	ctx->ra = 0;
	ctx->rb = 0;
	ctx->rr = 0;
	ctx->rra = 0;
	ctx->rrb = 0;
	ctx->rrr = 0;

	if ((ft_strcmp(ctx->strategy, "--simple") == 0)
		|| (((ft_strcmp(ctx->strategy, "--adaptive") == 0)
			|| ctx->strategy == NULL)
			&& ctx->disorder <= 0.2))
		insertion_sort(ctx);
	if (ctx->bench_flag)
		ft_putbench(ctx);
}
