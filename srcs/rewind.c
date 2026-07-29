/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:44:49 by aserio            #+#    #+#             */
/*   Updated: 2026/07/28 10:08:10 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rewind_a(t_context *ctx, size_t *c, size_t size)
{
	if (size / 2 > *c)
	{
		while (*c > 0)
		{
			op(OP_RRA, ctx);
			(*c)--;
		}
	}
	else
	{
		while (*c < size)
		{
			op(OP_RA, ctx);
			(*c)++;
		}
	}
}

void	rewind_b(t_context *ctx, size_t *c, size_t size)
{
	if (size / 2 >= *c)
	{
		while (*c > 0)
		{
			op(OP_RRB, ctx);
			(*c)--;
		}
	}
	else
	{
		while (*c < size)
		{
			op(OP_RB, ctx);
			(*c)++;
		}
	}
}
