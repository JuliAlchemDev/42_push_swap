/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 03:38:27 by aserio            #+#    #+#             */
/*   Updated: 2026/08/05 18:27:47 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

float	median_pivot(t_stack *stack, size_t size)
{
	size_t	c;
	size_t	i;
	size_t	j;
	float	pivot;

	pivot = 0;
	i = 0;
	c = 0;
	while (c != size / 2)
	{
		pivot = stack->data[i];
		c = 0;
		j = 0;
		while (j < size)
		{
			if (stack->data[j] <= pivot)
				c++;
			j++;
		}
		i++;
	}
	return (pivot);
}

void	quick_sort(t_context *ctx)
{
	quick_sort_a(ctx, (size_t) ctx->a->size);
}
