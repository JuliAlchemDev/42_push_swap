/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 16:03:07 by aserio            #+#    #+#             */
/*   Updated: 2026/07/26 08:18:44 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_stack
{
	int		*data;
	size_t	size;
}	t_stack;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_op;

typedef struct s_context	t_context;

typedef void				(*t_operation)(t_context *);

typedef struct s_action
{
	char		*name;
	int			count;
	t_operation	apply;
}	t_action;

typedef struct s_context
{
	int				bench_flag;
	float			disorder;
	char			*strategy;
	int				total_ops;
	t_action		*ops;
	t_stack			*a;
	t_stack			*b;
}	t_context;

#endif
