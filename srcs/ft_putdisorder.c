/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdisorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:38:13 by aserio            #+#    #+#             */
/*   Updated: 2026/07/03 18:15:51 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putdisorder(float d)
{
	int	decimals;

	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int) (d * 100), 2);
	ft_putchar_fd('.', 2);
	decimals = ((int) (d * 10000)) % 100;
	if (decimals < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimals, 2);
	ft_putendl_fd("%", 2);
}
