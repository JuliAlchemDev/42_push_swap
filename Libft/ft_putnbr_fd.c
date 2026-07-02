/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:25:27 by aserio            #+#    #+#             */
/*   Updated: 2026/05/19 19:48:27 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * Outputs the integer ’n’ to the specified file descriptor.
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		digit = '0' - (n % 10);
		n = -1 * (n / 10);
	}
	else
	{
		digit = '0' + (n % 10);
		n /= 10;
	}
	if (n > 0)
		ft_putnbr_fd(n, fd);
	ft_putchar_fd(digit, fd);
}
