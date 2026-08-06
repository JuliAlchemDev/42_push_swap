/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 18:19:11 by andrea            #+#    #+#             */
/*   Updated: 2026/05/15 18:28:33 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
/*
 * Allocates memory and returns a copy of ’s1’ with characters from ’set’
 * removed from the beginning and the end, or NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	end = ft_strlen(s1);
	while ((ft_strchr(set, (int)s1[end]) || s1[end] == '\0') && (0 < end))
		end--;
	start = 0;
	while (ft_strchr(set, (int)s1[start]) && (start <= end))
		start++;
	return (ft_substr(s1, start, end - start + 1));
}
