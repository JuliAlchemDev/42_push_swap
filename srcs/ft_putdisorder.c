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
	int		int_part;
	int		dec_part;
	char	*str_int;
	char	*str_dec;

	int_part = (int)(d * 100);
	dec_part = ((int)(d * 10000)) % 100;
	str_int = ft_itoa(int_part);
	str_dec = ft_itoa(dec_part);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putstr_fd(str_int, 2);
	if (dec_part < 10)
		ft_putstr_fd(".0", 2);
	else
		ft_putstr_fd(".", 2);
	ft_putstr_fd(str_dec, 2);
	ft_putendl_fd("%", 2);
	free(str_int);
	free(str_dec);
}
