/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:42:36 by iualkhim          #+#    #+#             */
/*   Updated: 2026/07/03 18:07:20 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insertion_sort(t_stack *a, t_stack *b, int bench_flag,
						t_bench_data *bench_data)
{
	size_t	count_rot;

	while (a->size >= 1)
	{
		count_rot = 0;
		while (a->data[0] < b->data[0] && count_rot < b->size)
		{
			rb(b);
			count_rot++;
		}
		pb(b, a);
		while (count_rot > 0)
		{
			rrb(b);
			count_rot--;
		}
	}
	while (b->size > 0)
		pa(a, b);
	if (bench_flag)
		ft_putbench(bench_data);
}
