/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 16:03:07 by aserio            #+#    #+#             */
/*   Updated: 2026/07/09 18:03:47 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_stack
{
	int		*data;
	size_t	size;
}	t_stack;

typedef	struct s_context
{
	int				bench_flag;
	float			disorder;
	char			*strategy;
	int				total_ops;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	t_stack			*a;
	t_stack			*b;	
}	t_context;


#endif
