/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:55:41 by aserio            #+#    #+#             */
/*   Updated: 2026/07/23 00:05:56 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	handle_simple_cases(t_context *ctx, size_t size)
{
	if (size == 2)
		if (ctx->a->data[0] > ctx->a->data[1])
			sa(ctx);
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
	while (j > pivot_index)
	{
		rra(ctx);
		j--;
	}
}

void	quick_sort_a(t_context *ctx, size_t size)
{
	float	pivot;
	size_t	pivot_index;
	size_t	j;
	size_t	pbs;

	if (size <= 2)
		return (handle_simple_cases(ctx, size));
	pivot_index = 0;
	pivot = avg_pivot(ctx->a, size);
	j = 0;
	pbs = count_pbs(ctx, size, pivot);
	while ((j < size) && (pivot_index < pbs))
	{
		if (ctx->a->data[0] <= pivot)
		{
			pb(ctx);
			pivot_index++;
		}
		else
			ra(ctx);
		j++;
	}
	rewind_stack(ctx, j, pivot_index);
	quick_sort_a(ctx, size - pivot_index);
	quick_sort_b(ctx, pivot_index);
}
