/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:42:36 by iualkhim          #+#    #+#             */
/*   Updated: 2026/07/03 16:52:44 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insertion_sort(t_stack *a)
{
	t_stack	*b;
	size_t	count_rot;
	size_t	limit;

	b = create_stack(a->size);
	while (a->size >= 1)
	{
		count_rot = 0;
		limit = b->size;
		while (a->data[0] < b->data[0] && count_rot < limit)
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
	clear_stack(b);
}
