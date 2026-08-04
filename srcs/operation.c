/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:00:44 by aserio            #+#    #+#             */
/*   Updated: 2026/08/03 20:34:22 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	init_operations_data(t_op_prop *ops_list)
{
	static const char *const	name_list[OP_COUNT] = {"sa", "sb", "ss", "pa",
		"pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	static const t_operation	apply_list[OP_COUNT] = {&sa, &sb, &ss, &pa,
		&pb, &ra, &rb, &rr, &rra, &rrb, &rrr};
	t_op						op;

	op = 0;
	while (op < OP_COUNT)
	{
		ops_list[op].name = ft_strdup(name_list[op]);
		ops_list[op].apply = apply_list[op];
		ops_list[op].count = 0;
		op++;
	}
}

void	init_operations_list(t_context *ctx)
{
	ctx->ops = calloc(OP_COUNT, sizeof(t_op_prop));
	if (!ctx->ops)
		error(ctx);
	init_operations_data(ctx->ops);
}

void	op(t_op op, t_context *ctx)
{
	if ((((op == OP_RA) || (op == OP_RRA)) && (ctx->a->size <= 1))
		|| (((op == OP_RB) || (op == OP_RRB)) && (ctx->b->size <= 1)))
		return ;
	ctx->ops[op].apply(ctx);
	ft_putendl_fd(ctx->ops[op].name, 1);
	ctx->ops[op].count++;
	ctx->total_ops++;
}
