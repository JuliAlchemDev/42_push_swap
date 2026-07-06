/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 11:02:52 by aserio            #+#    #+#             */
/*   Updated: 2026/07/03 18:08:32 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	select_sort(t_stack *a, t_stack *b, char strategy[], int bench_flag)
{
	t_bench_data	bench_data;

	bench_data.disorder = compute_disorder(a);
	bench_data.strategy = strategy;
	// Extract init bench_data
	bench_data.total_ops = 0;
	bench_data.sa = 0;
	bench_data.sb = 0;
	bench_data.ss = 0;
	bench_data.pa = 0;
	bench_data.pb = 0;
	bench_data.ra = 0;
	bench_data.rb = 0;
	bench_data.rr = 0;
	bench_data.rra = 0;
	bench_data.rrb = 0;
	bench_data.rrr = 0;

	if ((ft_strcmp(strategy, "--simple") == 0)
		|| ((ft_strcmp(strategy, "--adaptive") == 0)
			&& bench_data.disorder <= 0.2))
		insertion_sort(a, b, &bench_data);
	if (bench_flag)
		ft_putbench(&bench_data);
}
