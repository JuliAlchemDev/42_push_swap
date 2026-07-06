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

void	insertion_sort(t_stack *a, t_stack *b, t_bench_data *bench_data)
{
	size_t	count_rot;

	count_rot = 0;
	while (a->size >= 1)
	{
		count_rot = 0;
		while (a->data[0] < b->data[0] && count_rot < b->size)
		{
			bench_data->rb += rb(b);
			count_rot++;
		}
		bench_data->pb += pb(b, a);
		while (count_rot > 0)
		{
			bench_data->rrb += rrb(b);
			count_rot--;
		}
	}
	while (b->size > 0)
		bench_data->pa += pa(a, b);
}
