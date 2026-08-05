/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:42:51 by aserio            #+#    #+#             */
/*   Updated: 2026/08/05 16:57:06 by aserio           ###   ########.fr       */
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

	if (ctx->a->data[0] > ctx->a->data[1])
		op(OP_SA, ctx);
	op(OP_PB, ctx);
	op(OP_PB, ctx);
	i = 2;
	c = 0;
	while ((i < chunk_size) && (ctx->a->size > 4))
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
	}
	rewind_b(ctx, &c, i);
}

static	void	find_next_insertion_spot(t_context *ctx, size_t *c)
{
	size_t	i;

	i = 0;
	if (*c == 0
		&& ((ctx->b->data[0] > ctx->a->data[ctx->a->size - 1])
			|| (ctx->b->data[0] < ctx->a->data[0])))
		return ;
	else if ((ctx->b->data[0] < ctx->a->data[0])
		&& (ctx->b->data[0] > ctx->a->data[ctx->a->size - 1]))
		return ;
	if (ctx->b->data[0] < ctx->a->data[0])
	{
		i = ctx->a->size - *c;
		while (ctx->b->data[0] > ctx->a->data[i])
			i++;
	}
	else
	{
		while ((ctx->b->data[0] > ctx->a->data[i]) && (i < ctx->a->size - *c))
			i++;
	}
	*c = (*c + i) % ctx->a->size;
	i = ctx->a->size - i;
	rewind_a(ctx, &i, ctx->a->size);
	display_stacks(ctx);
}

static	void	merge_chunks(t_context *ctx)
{
	size_t	c;

	c = 0;
	while (ctx->b->size > 0)
	{
		find_next_insertion_spot(ctx, &c);
		op(OP_PA, ctx);
		if (ctx->a->data[0] < ctx->a->data[ctx->a->size - 1])
			c = 0;
		if (ctx->a->data[0] > ctx->a->data[1])
			c = ctx->a->size - 1;
	}
	rewind_a(ctx, &c, ctx->a->size);
}

void	chunk_sort(t_context *ctx)
{
	size_t	sqrt_n;

	sqrt_n = ft_floor_sqrt(ctx->a->size);
	while (ctx->a->size > 4)
		sort_chunk(ctx, sqrt_n);
	sort_a_small(ctx);
	merge_chunks(ctx);
}
