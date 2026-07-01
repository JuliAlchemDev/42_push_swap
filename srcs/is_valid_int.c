/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 20:22:48 by aserio            #+#    #+#             */
/*   Updated: 2026/06/30 17:35:56 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_int(char *s)
{
	char	*s2;
	int		r;

	s2 = ft_itoa(ft_atoi(s));
	if (!s2)
		return (0);
	r = !ft_strcmp(s, s2);
	free(s2);
	return (r);
}
