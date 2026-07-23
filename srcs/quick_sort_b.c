/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:57:18 by aserio            #+#    #+#             */
/*   Updated: 2026/07/22 22:32:49 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	handle_simple_cases(t_context *ctx, size_t size)
{
	if (size == 2)
	{
		if (ctx->b->data[0] < ctx->b->data[1])
			sb(ctx);
		pa(ctx);
	}
	pa(ctx);
}

static	size_t	count_pas(t_context *ctx, size_t size, int pivot)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < size)
	{
		if (ctx->b->data[i] <= pivot)
			count++;
		i++;
	}
	return (count);
}

static	void	rewind_stack(t_context *ctx, size_t j, size_t pivot_index)
{
	while (j > pivot_index)
	{
		rrb(ctx);
		j--;
	}
}

void	quick_sort_b(t_context *ctx, size_t size)
{
	float	pivot;
	size_t	pivot_index;
	size_t	j;
	size_t	pas;

	if (size <= 2)
		return (handle_simple_cases(ctx, size));
	pivot_index = 0;
	pivot = avg_pivot(ctx->b, size);
	j = 0;
	pas = count_pas(ctx, size, pivot);
	while ((j < size) && (pivot_index < pas))
	{
		if (ctx->b->data[0] >= pivot)
		{
			pa(ctx);
			pivot_index++;
		}
		else
			rb(ctx);
		j++;
	}
	rewind_stack(ctx, j, pivot_index);
	quick_sort_a(ctx, pivot_index);
	quick_sort_b(ctx, size - pivot_index);
}
