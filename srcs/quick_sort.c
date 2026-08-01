/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 03:38:27 by aserio            #+#    #+#             */
/*   Updated: 2026/08/01 12:33:13 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

float	avg_pivot(t_stack *stack, size_t size)
{
	size_t	i;
	float	pivot;

	pivot = 0;
	i = 0;
	while (i < size)
	{
		pivot += (float) stack->data[i];
		i++;
	}
	printf ("pivot = %f\n", (pivot / (float) size));
	return (pivot / (float) size);
}

void	quick_sort(t_context *ctx)
{
	display_stacks(ctx);
	quick_sort_a(ctx, (size_t) ctx->a->size);
	display_stacks(ctx);
}
