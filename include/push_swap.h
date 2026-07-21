/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:44:21 by aserio            #+#    #+#             */
/*   Updated: 2026/07/21 17:46:01 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "../libftprintf/ft_printf.h"
# include "structs.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

void			clear_stack(t_stack *s);
void			display_stacks(t_context *ctx);
t_stack			*load_stack(size_t size, char *nums[]);
void			putstack(t_stack *s);
int				is_valid_int(char *s);
int				ft_strcmp(const char *s1, const char *s2);
void			input_parser(int argc, char *argv[], t_context *ctx);
void			error(void);
void			ft_putdisorder(float d);
float			compute_disorder(t_stack *stack);
void			ft_putbench(t_context *ctx);
void			select_sort(t_context *ctx);

// Algorithms

void			bucket_sort(t_context *ctx);
void			insertion_sort(t_context *ctx);

// Operation functions

void			sa(t_context *ctx);
void			sb(t_context *ctx);
void			ss(t_context *ctx);

void			pa(t_context *ctx);
void			pb(t_context *ctx);

void			ra(t_context *ctx);
void			rb(t_context *ctx);
void			rr(t_context *ctx);

void			rra(t_context *ctx);
void			rrb(t_context *ctx);
void			rrr(t_context *ctx);

void			rewind_a(t_context *ctx, size_t *c);
void			rewind_b(t_context *ctx, size_t *c);

#endif
