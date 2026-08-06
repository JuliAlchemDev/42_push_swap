/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:13:19 by aserio            #+#    #+#             */
/*   Updated: 2026/05/08 19:39:49 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
/*
 * locates the first occurrence of the null-terminated string little in the 
 * string big, where not more than len characters are searched.
 * Characters that appear after a ‘\0’ character are not searched.
 *
 * If little is an empty string, big is returned;
 * if little occurs nowhere in big, NULL is returned;
 * otherwise a pointer to the first character of the first occurrence of little
 * is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && (i < len))
	{
		j = 0;
		while (little[j] && (little[j] == big[i + j]) && (i + j < len))
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
