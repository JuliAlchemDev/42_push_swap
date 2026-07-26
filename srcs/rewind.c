/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:44:49 by aserio            #+#    #+#             */
/*   Updated: 2026/07/25 11:49:40 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rewind_a(t_context *ctx, size_t *c)
{
	if (ctx->a->size / 2 > *c)
	{
		while (*c > 0)
		{
			op(RRA, ctx);
			(*c)--;
		}
	}
	else
	{
		while (*c < ctx->a->size)
		{
			op(RA, ctx);
			(*c)++;
		}
	}
}

void	rewind_b(t_context *ctx, size_t *c)
{
	if (ctx->b->size / 2 > *c)
	{
		while (*c > 0)
		{
			op(RRB, ctx);
			(*c)--;
		}
	}
	else
	{
		while (*c < ctx->b->size)
		{
			op(RB, ctx);
			(*c)++;
		}
	}
}
