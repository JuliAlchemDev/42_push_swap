/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:03:20 by aserio            #+#    #+#             */
/*   Updated: 2026/07/03 18:30:24 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void count_total(t_bench_data *bench_data)
{
	bench_data->total_ops += bench_data->sa;
	bench_data->total_ops += bench_data->sb;
	bench_data->total_ops += bench_data->ss;

	bench_data->total_ops += bench_data->pa;
	bench_data->total_ops += bench_data->pb;

	bench_data->total_ops += bench_data->ra;
	bench_data->total_ops += bench_data->rb;
	bench_data->total_ops += bench_data->rr;

	bench_data->total_ops += bench_data->rra;
	bench_data->total_ops += bench_data->rrb;
	bench_data->total_ops += bench_data->rrr;
}

void	ft_putbench(t_bench_data *bench_data)
{

	
	ft_putdisorder(bench_data->disorder);
	ft_printf("[bench] strategy: %s\n", bench_data->strategy);
	count_total(bench_data);
	ft_printf("[bench] total_ops: %d\n", bench_data->total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d", bench_data->sa, bench_data->sb, bench_data->ss);
	ft_printf(" pa: %d pb: %d\n",  bench_data->pa, bench_data->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d", bench_data->ra, bench_data->rb, bench_data->rr);
	ft_printf(" rra: %d rrb: %d rrr: %d\n", bench_data->rra, bench_data->rrb, bench_data->rrr);
}
