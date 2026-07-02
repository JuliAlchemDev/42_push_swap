/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:31:20 by aserio            #+#    #+#             */
/*   Updated: 2026/05/08 19:59:59 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
/*
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap.
 *
 * Returns a pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src != dest)
	{
		while (i < n)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dest);
}
