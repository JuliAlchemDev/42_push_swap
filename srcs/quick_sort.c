/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 03:38:27 by aserio            #+#    #+#             */
/*   Updated: 2026/07/22 21:57:11 by aserio           ###   ########.fr       */
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
	return (pivot / (float) size);
}

void	quick_sort(t_context *ctx)
{
	quick_sort_a(ctx, (size_t) ctx->a->size);
}
