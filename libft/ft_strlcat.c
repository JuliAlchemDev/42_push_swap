/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:40:23 by aserio            #+#    #+#             */
/*   Updated: 2026/05/08 16:22:11 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
/*
 * Take the full size of the buffer (not just the length) and guarantee to 
 * NUL-terminate the result as long as there is at least one byte free in dst.
 * Note that a byte for the NUL should be included in size.
 *
 * Returns the length of the total string they tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	j;

	dst_len = 0;
	while (dst[dst_len] && (dst_len < size))
		dst_len++;
	j = 0;
	if (dst_len + 1 < size)
	{
		while ((dst_len + j + 1 < size) && src[j])
		{
			dst[dst_len + j] = src[j];
			j++;
		}
		if (dst_len + j < size)
			dst[dst_len + j] = '\0';
	}
	while (src[j])
		j++;
	return (dst_len + j);
}
