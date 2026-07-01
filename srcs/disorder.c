/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 11:55:12 by aserio            #+#    #+#             */
/*   Updated: 2026/06/29 15:54:32 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

float	compute_disorder(t_stack *stack)
{
	size_t	mistakes;
	size_t	total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	j = 0;
	while (i < stack->size - 1)
	{
		while (j < stack->size)
		{
			mistakes = stack->data[i] > stack->data[j];
			total_pairs++;
			j++;
		}
		i++;
	}
	return ((float) mistakes / (float) total_pairs);
}
