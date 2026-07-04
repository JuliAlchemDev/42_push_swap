/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:44:21 by aserio            #+#    #+#             */
/*   Updated: 2026/07/03 18:11:21 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "../libftprintf/ft_printf.h"
# include "structs.h"
# include <stdlib.h>
# include <stdio.h>

void			clear_stack(t_stack *s);
void			display_stacks(t_stack *a, t_stack *b);
t_stack			*load_stack(size_t size, char *nums[]);
void			putstack(t_stack *s);
int				is_valid_int(char *s);
int				ft_strcmp(const char *s1, const char *s2);
t_parsed_input	input_parser(int argc, char *argv[]);
void			error(void);
void			ft_putdisorder(float d);
float			compute_disorder(t_stack *stack);
void			ft_putbench(t_bench_data *bench_data);
void			select_sort(t_stack *a, t_stack *b, char strategy[],
					int bench_flag);

// Algorithms

void			insertion_sort(t_stack *a, t_stack *b, int bench_flag,
					t_bench_data *bench_data);

// Operation functions

void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);

void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *b, t_stack *a);

void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);

void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);

#endif
