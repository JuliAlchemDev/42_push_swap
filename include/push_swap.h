/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:44:21 by aserio            #+#    #+#             */
/*   Updated: 2026/08/06 18:51:30 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "structs.h"
# include <stdlib.h>

void			clear_context(t_context *ctx);
void			clear_stack(t_stack *stack);
void			display_stacks(t_context *ctx);
t_stack			*load_stack(size_t size, char *nums[]);
void			putstack(t_stack *s);
void			init_operations_list(t_context *ctx);
int				is_valid_int(char *s);
int				ft_strcmp(const char *s1, const char *s2);
t_context		*input_parser(int argc, char *argv[]);
t_stack			*get_stack(int size, char **nums);
void			error(t_context *ctx);
void			ft_putdisorder(float d);
float			compute_disorder(t_stack *stack);
void			ft_putbench(t_context *ctx);
void			select_sort(t_context *ctx);

// Algorithms

// Simple
void			insertion_sort(t_context *ctx);
// Medium
void			chunk_sort(t_context *ctx);
void			sort_a_small(t_context *ctx);
// Complex
void			quick_sort(t_context *ctx);
void			quick_sort_a(t_context *ctx, size_t size);
void			quick_sort_b(t_context *ctx, size_t size);
float			median_pivot(t_stack *stack, size_t size);

// Operations wrapper

void			op(t_op op, t_context *ctx);

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

void			rewind_a(t_context *ctx, size_t *c, size_t size);
void			rewind_b(t_context *ctx, size_t *c, size_t size);

#endif
