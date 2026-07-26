/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:00:44 by aserio            #+#    #+#             */
/*   Updated: 2026/07/26 08:47:19 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	init_operations_names(t_action *ops_list)
{
	ops_list[PA].name = ft_strdup("pa");
	ops_list[PB].name = ft_strdup("pb");
	ops_list[SA].name = ft_strdup("sa");
	ops_list[SB].name = ft_strdup("sb");
	ops_list[SS].name = ft_strdup("ss");
	ops_list[RA].name = ft_strdup("ra");
	ops_list[RB].name = ft_strdup("rb");
	ops_list[RR].name = ft_strdup("rr");
	ops_list[RRA].name = ft_strdup("rra");
	ops_list[RRB].name = ft_strdup("rrb");
	ops_list[RRR].name = ft_strdup("rrr");
}

static	void	init_operations(t_action *ops_list)
{
	ops_list[PA].apply = &pa;
	ops_list[PB].apply = &pb;
	ops_list[SA].apply = &sa;
	ops_list[SB].apply = &sb;
	ops_list[SS].apply = &ss;
	ops_list[RA].apply = &ra;
	ops_list[RB].apply = &rb;
	ops_list[RR].apply = &rr;
	ops_list[RRA].apply = &rra;
	ops_list[RRB].apply = &rrb;
	ops_list[RRR].apply = &rrr;
}

static	void	init_counts(t_action *ops_list)
{
	ops_list[PA].count = 0;
	ops_list[PB].count = 0;
	ops_list[SA].count = 0;
	ops_list[SB].count = 0;
	ops_list[SS].count = 0;
	ops_list[RA].count = 0;
	ops_list[RB].count = 0;
	ops_list[RR].count = 0;
	ops_list[RRA].count = 0;
	ops_list[RRB].count = 0;
	ops_list[RRR].count = 0;
}

void	init_operations_list(t_context *ctx)
{
	ctx->ops = calloc(OP_COUNT, sizeof(t_action));
	if (!ctx->ops)
		error(ctx);
	init_operations_names(ctx->ops);
	init_operations(ctx->ops);
	init_counts(ctx->ops);
}

void	op(t_op op, t_context *ctx)
{
	ctx->ops[op].apply(ctx);
	ft_putendl_fd(ctx->ops[op].name, 1);
	ctx->ops[op].count++;
	ctx->total_ops++;
}
