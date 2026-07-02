/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:49:23 by aserio            #+#    #+#             */
/*   Updated: 2026/05/08 20:12:51 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
/*
 * returns a pointer to a new string which is a duplicate of the string s.
 * Memory for the new string is obtained with malloc, and can be freed with
 * free.
 *
 * On success, the function returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available, with errno set to
 * indicate the cause of the error.
 */
char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*sdup;

	len = 0;
	while (s[len])
		len++;
	sdup = malloc(len + 1);
	if (!sdup)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		sdup[i] = s[i];
		i++;
	}
	return (sdup);
}
