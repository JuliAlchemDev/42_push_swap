/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:42:51 by aserio            #+#    #+#             */
/*   Updated: 2026/07/09 16:01:54 by aserio           ###   ########.fr       */
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

void	sort_chunk(t_context *ctx, size_t chunk_size)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (ctx->a->data[0] < ctx->a->data[1])
		sa(ctx);
	pb(ctx);
	pb(ctx);
	while ((i < chunk_size) && (ctx->a->size > 0))
	{
		if (ctx->a->data[0] < ctx->b->data[0])
		{
			pb(ctx);
			i++;
		}
		else
		{
			rrb(ctx);
			c++;
		}
	}
}

void	bucket_sort(t_context *ctx)
{
	size_t	sqrt_n;
	size_t	i;
	size_t	j;
	size_t	c;

	sqrt_n = ft_floor_sqrt(ctx->a->size);
	while (ctx->a->size > 0)
	{
		i = 0;
	}
}
