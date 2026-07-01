/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:03:45 by aserio            #+#    #+#             */
/*   Updated: 2026/06/30 17:22:24 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	putstack(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		ft_putnbr_fd(stack->data[i], 1);
		if (i < stack->size - 1)
			ft_putstr_fd(", ", 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}
