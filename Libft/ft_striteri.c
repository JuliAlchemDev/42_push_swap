/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:00:37 by aserio            #+#    #+#             */
/*   Updated: 2026/05/19 19:02:52 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Applies the function ’f’ to each character of the string passed as argument,
 * passing its index as the first argument.
 * Each character is passed by address to ’f’ so it can be modified if
 * necessary.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
