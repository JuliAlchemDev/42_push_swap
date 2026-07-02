/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:49:24 by aserio            #+#    #+#             */
/*   Updated: 2026/05/08 19:20:43 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
/*
 * returns a pointer to the first occurrence of the character c in the string s
 * or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && (s[i] != (char)c))
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
