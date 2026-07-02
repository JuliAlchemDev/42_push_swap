/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:30:42 by aserio            #+#    #+#             */
/*   Updated: 2026/05/12 23:42:16 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
/*
 * Allocates memory (using malloc) and returns a substring from the string ’s’
 * or NULL if the allocation fails.
 * The substring starts at index ’start’ and has a maximum length of ’len’.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			slen;

	slen = ft_strlen(s);
	if (start < slen)
	{
		if (slen < start + len)
			sub = malloc(slen - start + 1);
		else
			sub = malloc(len + 1);
	}
	else
		sub = malloc(1);
	if (!sub)
		return (NULL);
	i = 0;
	while ((start + i < slen) && (i < len))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
