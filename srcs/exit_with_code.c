/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:08:12 by aserio            #+#    #+#             */
/*   Updated: 2026/08/07 13:39:07 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_with_code(int code, t_context *ctx)
{
	clear_context(ctx);
	if (code)
		ft_putendl_fd("Error", 2);
	exit (code);
}
