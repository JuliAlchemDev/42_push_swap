/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdisorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:38:13 by aserio            #+#    #+#             */
/*   Updated: 2026/07/09 18:23:08 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putdisorder(float d)
{
	int	int_part;
	int	dec_part;

	int_part = (int)(d * 100);
	dec_part = ((int)(d * 10000)) % 100;
	ft_printf("[bench] disorder: ");
	if (dec_part < 10)
		ft_printf("%d.0%d%%\n", int_part, dec_part);
	else
		ft_printf("%d.%d%%\n", int_part, dec_part);
}
