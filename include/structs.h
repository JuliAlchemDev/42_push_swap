/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 16:03:07 by aserio            #+#    #+#             */
/*   Updated: 2026/07/09 18:21:17 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_stack
{
	int		*data;
	size_t	size;
}	t_stack;

typedef enum	e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
} t_op;

typedef struct s_context
{
	int				bench_flag;
	float			disorder;
	char			*strategy;
	int				total_ops;
	int				ops[OP_COUNT];
	t_stack			*a;
	t_stack			*b;
}	t_context;

#endif
