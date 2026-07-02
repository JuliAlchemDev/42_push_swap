/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:17:17 by aserio            #+#    #+#             */
/*   Updated: 2026/05/08 18:39:08 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
/*
 * scans the initial n bytes of the memory area pointed to by s for the first
 * instance of c. Both c and the bytes of the memory area pointed to by s are
 * interpreted as unsigned char.
 *
 *  Returns a pointer to the matching byte or NULL if the character does not
 *  occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			if ((unsigned char)c == *(unsigned char *)(s + i))
				return ((void *)(s + i));
			i++;
		}
	}
	return (NULL);
}
