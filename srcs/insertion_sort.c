/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:42:36 by iualkhim          #+#    #+#             */
/*   Updated: 2026/07/27 14:46:59 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static size_t	find_insert_pos(t_stack *b, int value)
// {
// 	size_t	i;
// 	size_t	pos;

// 	i = 0;
// 	pos = 0;
// 	while (i < b->size)
// 	{
// 		if(b->data[i] > value)
// 			pos++;
// 		i++;
// 	}
// 	return (pos);
// }

static size_t	find_insert_pos(t_stack *b, int value)
{
	size_t	i;
	int		current;
	int		next;

	i = 0;
	while (i < b->size)
	{
		current = b->data[i];
		next = b->data[(i + 1) % b->size];
		if (current > value && value > next)
			return (i + 1);
		if (current < next)
		{
			if (value > next || value < current)
				return (i + 1);
		}
		i++;
	}
	return (0);
}

static void	rotate_to_pos(t_context *ctx, size_t pos)
{
	if (pos <= ctx->b->size / 2)
	{
		while (pos--)
			op(OP_RB, ctx);
	}
	else
	{
		pos = ctx->b->size - pos;
		while (pos--)
			op(OP_RRB, ctx);
	}
}

static size_t	find_max_pos(t_stack *b)
{
	size_t	i;
	size_t	max_pos;

	max_pos = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->data[i] > b->data[max_pos])
			max_pos = i;
		i++;
	}
	return (max_pos);
}

void	insertion_sort(t_context *ctx)
{
	size_t	pos;

	pos = 0;
	while (ctx->a->size >= 1)
	{
		// if(ctx->a->size > 1 && ctx->a->data[0] < ctx->a->data[1])
		// 	op(OP_SA, ctx);
		if (ctx->b->size == 0)
		{
			op(OP_PB, ctx);
			continue ;
		}
		pos = find_insert_pos(ctx->b, ctx->a->data[0]);
		rotate_to_pos(ctx, pos);
		op(OP_PB, ctx);
	}
	if (ctx->a->size == 0)
	{
		pos = find_max_pos(ctx->b);
		rotate_to_pos(ctx, pos);
	}
	while (ctx->b->size > 0)
		op(OP_PA, ctx);
}

// void	insertion_sort(t_context *ctx)
// {
// 	size_t	count_rot;

// 	count_rot = 0;
// 	while (ctx->a->size >= 1)
// 	{
// 		count_rot = 0;
// 		while (ctx->a->data[0] < ctx->b->data[0] && count_rot < ctx->b->size)
// 		{
// 			op(OP_RB, ctx);
// 			count_rot++;
// 		}
// 		op(OP_PB, ctx);
// 		while (count_rot > 0)
// 		{
// 			op(OP_RRB, ctx);
// 			count_rot--;
// 		}
// 	}
// 	while (ctx->b->size > 0)
// 		op(OP_PA, ctx);
// }
