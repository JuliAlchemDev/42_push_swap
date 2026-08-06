/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:34:07 by aserio            #+#    #+#             */
/*   Updated: 2026/05/19 17:17:55 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
/*
 * Allocates memory (using malloc) and returns an array of strings obtained by
 * splitting ’s’ using the character ’c’ as a delimiter.
 * Each string in the returned array is allocated independently.
 * The array of pointers itself is also allocated dynamically.
 * The returned array must be NULL terminated.
 */
static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static void	free_all(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**fill_split(char const *s, char c, char **out)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (out);
		len = word_len(s, c);
		out[i] = ft_substr(s, 0, len);
		if (!out[i])
		{
			free_all(out, i);
			return (NULL);
		}
		s += len;
		i++;
	}
	return (out);
}

char	**ft_split(char const *s, char c)
{
	char	**out;

	if (!s)
		return (NULL);
	out = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!out)
		return (NULL);
	return (fill_split(s, c, out));
}
