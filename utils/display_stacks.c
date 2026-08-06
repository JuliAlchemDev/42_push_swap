/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 12:27:16 by aserio            #+#    #+#             */
/*   Updated: 2026/08/06 20:09:13 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	display_stacks(t_context *ctx)
{
	if (1)
	{
		ft_putendl_fd("--------------------------------------------", 1);
		ft_putstr_fd("a.size = ", 1);
		ft_putnbr_fd(ctx->a->size, 1);
		ft_putstr_fd("\t| ", 1);
		putstack(ctx->a);
		ft_putendl_fd("----------", 1);
		ft_putstr_fd("b.size = ", 1);
		ft_putnbr_fd(ctx->b->size, 1);
		ft_putstr_fd("\t| ", 1);
		putstack(ctx->b);
		ft_putendl_fd("----------", 1);
		ft_putstr_fd("disorder = ", 1);
		ft_putdisorder(compute_disorder(ctx->a));
		ft_putendl_fd("--------------------------------------------", 1);
	}
}
