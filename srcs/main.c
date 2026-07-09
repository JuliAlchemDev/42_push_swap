/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:27:22 by aserio            #+#    #+#             */
/*   Updated: 2026/07/09 15:20:22 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_parsed_input	parsed_input;
	t_context		ctx;

	parsed_input = input_parser(argc, argv);
	ctx.a = parsed_input.stack;
	ctx.b = load_stack(ctx.a->size, NULL);
	ctx.bench_flag = parsed_input.bench_flag;
	ctx.strategy = parsed_input.strategy;
	ctx.bench_flag = parsed_input.bench_flag;
	select_sort(&ctx);
	clear_stack(ctx.b);
	clear_stack(ctx.a);
	return (0);
}
