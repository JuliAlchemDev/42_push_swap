/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:42:36 by iualkhim          #+#    #+#             */
/*   Updated: 2026/07/27 14:46:59 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insertion_sort(t_context *ctx)
{
	size_t	count_rot;

	count_rot = 0;
	while (ctx->a->size >= 1)
	{
		count_rot = 0;
		while (ctx->a->data[0] < ctx->b->data[0] && count_rot < ctx->b->size)
		{
			op(OP_RB, ctx);
			count_rot++;
		}
		op(OP_PB, ctx);
		while (count_rot > 0)
		{
			op(OP_RRB, ctx);
			count_rot--;
		}
	}
	while (ctx->b->size > 0)
		op(OP_PA, ctx);
}
