/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 11:02:52 by aserio            #+#    #+#             */
/*   Updated: 2026/07/21 16:04:57 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	select_sort(t_context *ctx)
{
	if (ctx->disorder > 0)
	{
		if ((ft_strcmp(ctx->strategy, "--simple") == 0)
			|| (((ft_strcmp(ctx->strategy, "--adaptive") == 0)
					|| ctx->strategy == NULL)
				&& ctx->disorder <= 0.2))
			insertion_sort(ctx);
		if ((ft_strcmp(ctx->strategy, "--medium") == 0)
			|| (((ft_strcmp(ctx->strategy, "--adaptive") == 0)
					|| ctx->strategy == NULL)
				&& ctx->disorder <= 0.5))
			bucket_sort(ctx);
	}
	if (ctx->bench_flag)
		ft_putbench(ctx);
}
