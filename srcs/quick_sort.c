/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 03:38:27 by aserio            #+#    #+#             */
/*   Updated: 2026/07/22 21:40:20 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	quick_sort_b(t_context *ctx, size_t size);

static	float	avg_pivot(t_stack *stack, size_t size)
{
	size_t	i;
	float	pivot;

	pivot = 0;
	i = 0;
	while (i < size)
	{
		printf("%d, ", stack->data[i]);
		pivot += (float) stack->data[i];
		i++;
	}
	printf("\n");
	return (pivot / (float) size);
}

static	void	quick_sort_a(t_context *ctx, size_t size)
{
	float	pivot;
	size_t	pivot_index;
	size_t	j;

	if (size == 1)
		return ;
	if (size == 2)
	{
		if (ctx->a->data[0] > ctx->a->data[1])
			sa(ctx);
		return;
	}
	pivot_index = 0;
	pivot = avg_pivot(ctx->a, size);
	display_stacks(ctx);
	printf("stack a, size = %d, pivot = %f\n", (int) size, pivot);
	j = 0;
	while (j < size)
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
	while (j > pivot_index)
	{
		rra(ctx);
		j--;
	}
	if (size == 0)
		exit(1);
	quick_sort_a(ctx, size - pivot_index);
	quick_sort_b(ctx, pivot_index);
}

static	void	quick_sort_b(t_context *ctx, size_t size)
{
	float	pivot;
	size_t	pivot_index;
	size_t	j;

	if (size == 1)
	{
		pa(ctx);
		return;
	}
	if (size == 2)
	{
		if (ctx->b->data[0] < ctx->b->data[1])
			sb(ctx);
		pa(ctx);
		pa(ctx);
		return;
	}
	pivot_index = 0;
	pivot = avg_pivot(ctx->b, size);
	display_stacks(ctx);
	printf("stack b, size = %d, pivot = %f\n", (int) size, pivot);
	j = 0;
	while (j < size)
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
	while (j > pivot_index)
	{
		rrb(ctx);
		j--;
	}
	quick_sort_a(ctx, pivot_index);
	quick_sort_b(ctx, size - pivot_index);
}

void	quick_sort(t_context *ctx)
{
	quick_sort_a(ctx, (size_t) ctx->a->size);
}
