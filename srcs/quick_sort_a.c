/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:55:41 by aserio            #+#    #+#             */
/*   Updated: 2026/08/06 12:57:22 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	sort_four(t_context *ctx);

static	void	handle_simple_cases(t_context *ctx, size_t size)
{
	if (size == 2)
	{
		if (ctx->a->data[0] > ctx->a->data[1])
			op(OP_SA, ctx);
		return ;
	}
	if (size == ctx->a->size)
		return (sort_a_small(ctx));
	if (size == 3)
	{
		if (ctx->a->data[0] > ctx->a->data[1])
			op(OP_SA, ctx);
		if (ctx->a->data[1] > ctx->a->data[2])
		{
			op(OP_RA, ctx);
			op(OP_SA, ctx);
			op(OP_RRA, ctx);
		}
		if (ctx->a->data[0] > ctx->a->data[1])
			op(OP_SA, ctx);
	}
	if (size == 4)
		sort_four(ctx);
}

static	void	sort_four(t_context *ctx)
{
	{
		if (ctx->a->data[0] > ctx->a->data[1])
			op(OP_SA, ctx);
		if ((ctx->a->data[1] > ctx->a->data[2])
			|| (ctx->a->data[1] > ctx->a->data[3])
			|| (ctx->a->data[2] > ctx->a->data[3]))
		{
			op(OP_RA, ctx);
			handle_simple_cases(ctx, 3);
			op(OP_RRA, ctx);
		}
		handle_simple_cases(ctx, 3);
	}
}

static	size_t	count_pbs(t_context *ctx, size_t size, int pivot)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < size)
	{
		if (ctx->a->data[i] <= pivot)
			count++;
		i++;
	}
	return (count);
}

static	void	rewind_stack(t_context *ctx, size_t j, size_t pivot_index)
{
	if (pivot_index == ctx->a->size)
		rewind_a(ctx, &j, pivot_index);
	while (j > pivot_index)
	{
		op(OP_RRA, ctx);
		j--;
	}
}

void	quick_sort_a(t_context *ctx, size_t size)
{
	float	pivot;
	size_t	pivot_index;
	size_t	j;
	size_t	pbs;

	if (size <= 4)
		return (handle_simple_cases(ctx, size));
	pivot_index = 0;
	pivot = median_pivot(ctx->a, size);
	j = 0;
	pbs = count_pbs(ctx, size, pivot);
	while ((j < size) && (pivot_index < pbs))
	{
		if (ctx->a->data[0] <= pivot)
		{
			op(OP_PB, ctx);
			pivot_index++;
		}
		else
			op(OP_RA, ctx);
		j++;
	}
	rewind_stack(ctx, j, pivot_index);
	quick_sort_a(ctx, size - pivot_index);
	quick_sort_b(ctx, pivot_index);
}
