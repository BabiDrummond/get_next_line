/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:48:11 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/27 22:16:05 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_digits(int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int	ft_putnbr_base_fd(long n, char *set, int base, int fd)
{
	int	digits;

	digits = count_digits(n, base);
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n / base)
		ft_putnbr_base_fd(n / base, set, base, fd);
	write(fd, &set[n % base], 1);
	return (digits);
}

/*
int main(void)
{
	#include <stdio.h>
	printf("\n%d\n", ft_putnbr_base_fd(46, "0123456789abcdef", 16, 1));
}
*/