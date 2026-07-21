/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:44:49 by aserio            #+#    #+#             */
/*   Updated: 2026/07/21 17:58:42 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rewind_a(t_context *ctx, size_t *c)
{
	if (ctx->a->size / 2 > *c)
	{
		while (*c > 0)
		{
			rra(ctx);
			(*c)--;
		}
	}
	else
	{
		while (*c < ctx->a->size)
		{
			ra(ctx);
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
			rrb(ctx);
			(*c)--;
		}
	}
	else
	{
		while (*c < ctx->b->size)
		{
			rb(ctx);
			(*c)++;
		}
	}
}
