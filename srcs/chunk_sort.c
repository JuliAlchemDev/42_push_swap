/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:42:51 by aserio            #+#    #+#             */
/*   Updated: 2026/07/27 20:54:49 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	size_t	ft_floor_sqrt(size_t n)
{
	size_t	r;

	if (n <= 1)
		return (1);
	r = (n + 21) / 8;
	while (r > n / r)
		r = (n / r + r) / 2;
	if (r * r <= n)
		return (r);
	return (0);
}

static	void	sort_chunk(t_context *ctx, size_t chunk_size)
{
	size_t	c;
	size_t	i;

	printf("Chunk size = %lu\n", chunk_size);
	if (ctx->a->data[0] > ctx->a->data[1])
		op(OP_SA, ctx);
	op(OP_PB, ctx);
	op(OP_PB, ctx);
	i = 2;
	c = 0;
	while ((i < chunk_size) && (ctx->a->size > 3))
	{
		while ((ctx->a->data[0] > ctx->b->data[ctx->b->size - 1]) && (c > 0))
		{
			op(OP_RRB, ctx);
			c--;
		}
		while ((ctx->a->data[0] < ctx->b->data[0]) && (c < i))
		{
			op(OP_RB, ctx);
			c++;
		}
		op(OP_PB, ctx);
		i++;
		display_stacks(ctx);
	}
	rewind_b(ctx, &c, i);
	display_stacks(ctx);
}

static	void	merge_chunks(t_context *ctx, size_t chunk_size)
{
	size_t	c;
	size_t	i;

	c = 0;
	i = 0;
	while (ctx->b->size > 0)
	{
		while ((ctx->b->data[0] < ctx->a->data[0]) && (c < ctx->a->size))
		{
			op(OP_RA, ctx);
			c++;
		}
		while ((ctx->b->data[0] > ctx->a->data[0]) && (c < ctx->a->size))
		{
			op(OP_RA, ctx);
			c++;
		}
		if (ctx->b->data[0] < ctx->a->data[0])
			c %= ctx->a->size;
		op(OP_PA, ctx);
		i++;
		c %= ctx->a->size;
		display_stacks(ctx);
	}
	rewind_a(ctx, &c, ctx->a->size);
	display_stacks(ctx);
}

void	chunk_sort(t_context *ctx)
{
	size_t	sqrt_n;

	sqrt_n = ft_floor_sqrt(ctx->a->size);
	display_stacks(ctx);
	while (ctx->a->size > 3)
		sort_chunk(ctx, sqrt_n);
	sort_a_simple(ctx);
	merge_chunks(ctx, sqrt_n);
}
