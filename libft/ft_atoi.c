/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:27:45 by aserio            #+#    #+#             */
/*   Updated: 2026/05/09 17:58:27 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * The atoi() function converts the initial portion of the string pointed to by
 * nptr to int.
 * The behavior is the same as strtol(nptr, NULL, 10);
 * except that atoi() does not detect errors.
 *
 * In the "C" and "POSIX" locales white spaces are the following:
 *    - space,
 *    - form-feed ('\f'),
 *    - newline ('\n'),
 *    - carriage return ('\r'),
 *    - horizontal tab ('\t'), and
 *    - vertical tab ('\v').
 */
static	int	is_white_space(char c)
{
	if ((c == ' ')
		|| (c == '\f')
		|| (c == '\n')
		|| (c == '\r')
		|| (c == '\t')
		|| (c == '\v'))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	while (is_white_space(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] == '0')
		i++;
	n = 0;
	while (('0' <= nptr[i]) && (nptr[i] <= '9'))
	{
		n = n * 10 + (int)(nptr[i] - '0');
		i++;
	}
	return (sign * n);
}
