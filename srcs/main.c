/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:27:22 by aserio            #+#    #+#             */
/*   Updated: 2026/07/09 18:05:13 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
// int	main(void)
{
	t_context		ctx;

	input_parser(argc, argv, &ctx);
	select_sort(&ctx);
	
	// ft_printf("%d\n", parsed_input.strategy);

	// ft_putbench(&ctx);


	// ctx.bench_flag = 1;
	// ctx.disorder = 0;
	// // ctx.strategy = "--simple";
	// // ctx.strategy = "--medium";
	// // ctx.strategy = "--complex";
	// ctx.strategy = "--adaptive";
	// ctx.total_ops = 12;
	// ctx.sa = 0;
	// ctx.sb = 0;
	// ctx.ss = 0;
	// ctx.pa = 0;
	// ctx.pb = 0;
	// ctx.ra = 0;
	// ctx.rb = 0;
	// ctx.rr = 0;
	// ctx.rra = 0;
	// ctx.rrb = 0;
	// ctx.rrr = 0;
	// ctx.a = NULL;
	// ctx.b = NULL;
	//ft_putbench(&ctx);
	
	clear_stack(ctx.b);
	clear_stack(ctx.a);
	return (0);
}
