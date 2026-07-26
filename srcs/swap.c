/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:59:01 by aserio            #+#    #+#             */
/*   Updated: 2026/07/24 23:40:28 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->data[0];
		stack->data[0] = stack->data[1];
		stack->data[1] = temp;
	}
}

void	sa(t_context *ctx)
{
	swap(ctx->a);
}

void	sb(t_context *ctx)
{
	swap(ctx->b);
}

void	ss(t_context *ctx)
{
	sa(ctx);
	sb(ctx);
}
