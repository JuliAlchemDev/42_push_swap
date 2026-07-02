/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 12:27:16 by aserio            #+#    #+#             */
/*   Updated: 2026/06/28 12:49:22 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	display_stacks(t_stack *a, t_stack *b)
{
	ft_putendl_fd("--------------------------------------------", 1);
	ft_putstr_fd("a - size = ", 1);
	ft_putnbr_fd(a->size, 1);
	ft_putchar_fd('\n', 1);
	putstack(a);
	ft_putstr_fd("b - size = ", 1);
	ft_putnbr_fd(b->size, 1);
	ft_putchar_fd('\n', 1);
	putstack(b);
	ft_putendl_fd("--------------------------------------------", 1);
}
