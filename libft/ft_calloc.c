/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:03:59 by aserio            #+#    #+#             */
/*   Updated: 2026/05/08 20:23:59 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
/*
 * The  calloc()  function allocates memory for an array of nmemb elements of
 * size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero.
 * If nmemb or size is 0, then calloc() returns either NULL, or a unique pointer
 * value that can later be successfully passed to free().
 * If the multiplication of nmemb and size would result in integer overflow,
 * then calloc() returns an error.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	tot;
	size_t	i;

	if ((size == 0) || (nmemb == 0))
		return ((void *)malloc(0));
	tot = nmemb * size;
	if (nmemb != tot / size)
		return (NULL);
	ptr = malloc(tot);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < tot)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
