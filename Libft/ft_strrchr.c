/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:49:24 by andrea            #+#    #+#             */
/*   Updated: 2026/05/08 19:31:00 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
/*
 * returns a pointer to the last occurrence of the character c in the string s
 * or NULL if the character is not found.
 * The terminating null byte is considered part of the string, so that if c is
 * specified as '\0', these functions return a pointer to the terminator.
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*match;

	i = 0;
	match = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			match = (char *)s + i;
		i++;
	}
	if (s[i] == (char)c)
		match = (char *)s + i;
	return (match);
}
