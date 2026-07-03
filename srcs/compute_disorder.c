/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 11:55:12 by aserio            #+#    #+#             */
/*   Updated: 2026/07/03 17:12:52 by aserio           ###   ########.fr       */
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
	if (stack->size <= 1)
		return (1.0);
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			total_pairs++;
			if (stack->data[i] > stack->data[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((float)mistakes / (float)total_pairs);
}
