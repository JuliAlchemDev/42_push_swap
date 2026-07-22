/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:27:22 by aserio            #+#    #+#             */
/*   Updated: 2026/07/22 13:15:16 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_context		ctx;

	input_parser(argc, argv, &ctx);
	display_stacks(&ctx);
	select_sort(&ctx);
	display_stacks(&ctx);
	clear_stack(ctx.b);
	clear_stack(ctx.a);
	return (0);
}
