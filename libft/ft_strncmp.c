/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:59:02 by aserio            #+#    #+#             */
/*   Updated: 2026/05/08 18:28:26 by aserio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
/*
 * returns an integer indicating the result of the comparison, between the first
 * n bytes of s1 and s2 as follows:
 *
 *  •  0, if the s1 and s2 are equal;
 *  •  a negative value if s1 is less than s2;
 *  •  a positive value if s1 is greater than s2.
 *
 *  The sign of a nonzero return value shall be determined by the sign of the
 *  difference between the  values  of the first pair of bytes (both interpreted
 *  as type unsigned char) that differ in the strings being compared.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	else
		while ((i + 1 < n) && (s1[i] == s2[i]) && s1[i])
			i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
