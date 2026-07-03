/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:27:22 by aserio            #+#    #+#             */
/*   Updated: 2026/07/03 18:18:05 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;
	t_parsed_input	parsed_input;

	parsed_input = input_parser(argc, argv);
	a = parsed_input.stack;
	b = load_stack(a->size, NULL);
	select_sort(a, b, parsed_input.strategy, parsed_input.bench_flag);
	clear_stack(a);
	clear_stack(b);
	return (0);
}
