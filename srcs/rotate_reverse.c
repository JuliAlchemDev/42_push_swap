/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:46:29 by aserio            #+#    #+#             */
/*   Updated: 2026/07/09 15:06:16 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rvs_rotate(t_stack *stack)
{
	int	temp;
	int	i;
	int	size;

	size = stack->size;
	temp = stack->data[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = temp;
}

void	rra(t_context *ctx)
{
	rvs_rotate(ctx->a);
	ctx->rra++;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_context *ctx)
{
	rvs_rotate(ctx->b);
	ctx->rrb++;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_context *ctx)
{
	rvs_rotate(ctx->a);
	rvs_rotate(ctx->b);
	ctx->rrr++;
	ft_putendl_fd("rrr", 1);
}
