/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:16:15 by aserio            #+#    #+#             */
/*   Updated: 2026/05/07 12:24:54 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
/*
 * Copy a string. Copy src to string dst of size siz.
 * At most siz-1 characters will be copied.
 * Always NULL terminates (unless siz == 0).
 *
 * The strlcpy() function returns strlen(src).
 * If retval >= siz, truncation occurred.
 *
 * Copy src to string dst of size siz. At most siz-1 characters will be copied.
 * Always NULL terminates (unless siz == 0).
 *
 * The strlcpy() function returns strlen(src).
 * If retval >= siz, truncation occurred.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	len;

	len = 0;
	while ((src[len]) && (len + 1 < siz))
	{
		dst[len] = src[len];
		len++;
	}
	if ((!src[len]) || (len + 1 == siz))
		dst[len] = '\0';
	while (src[len])
		len++;
	return (len);
}
