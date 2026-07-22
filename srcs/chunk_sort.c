/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:42:51 by aserio            #+#    #+#             */
/*   Updated: 2026/07/21 18:14:03 by aserio           ###   ########.fr       */
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

	pb(ctx);
	i = 1;
	while ((i < chunk_size) && (ctx->a->size > 1))
	{
		c = 0;
		while ((ctx->a->data[0] > ctx->b->data[0]) && (c < i))
		{
			rb(ctx);
			c++;
		}
		pb(ctx);
		i++;
		while ((ctx->a->data[0] < ctx->b->data[0]) && (c > 0))
		{
			rrb(ctx);
			c--;
		}
	}
	rewind_b(ctx, &c);
}

static	void	merge_chunks(t_context *ctx)
{
	size_t	c;

	c = 0;
	while (ctx->b->size > 0)
	{
		while ((ctx->b->data[0] > ctx->a->data[0]) && (c < ctx->a->size))
		{
			ra(ctx);
			c++;
		}
		if (ctx->b->data[0] < ctx->a->data[0])
			c %= ctx->a->size;
		pa(ctx);
		while ((ctx->b->data[0] < ctx->a->data[0]) && (c < ctx->a->size))
		{
			ra(ctx);
			c++;
		}
		c %= ctx->a->size;
	}
	rewind_a(ctx, &c);
}

void	chunk_sort(t_context *ctx)
{
	size_t	sqrt_n;

	sqrt_n = ft_floor_sqrt(ctx->a->size);
	while (ctx->a->size > 1)
		sort_chunk(ctx, sqrt_n);
	merge_chunks(ctx);
}
