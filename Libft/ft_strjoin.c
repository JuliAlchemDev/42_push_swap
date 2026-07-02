/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 21:06:28 by aserio            #+#    #+#             */
/*   Updated: 2026/05/09 18:18:42 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
/*
 * Allocates memory (using malloc(3)) and returns a new string, which is the
 * result of concatenating ’s1’ and ’s2’ or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*join;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = malloc(s1_len + s2_len + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		join[s1_len + i] = s2[i];
		i++;
	}
	join[s1_len + s2_len] = '\0';
	return (join);
}
