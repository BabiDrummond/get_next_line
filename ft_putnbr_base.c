/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:48:11 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/28 19:25:58 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_digits(long n, int base)
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

int	ft_putnbr_base(long n, char *set, int base)
{
	int	digits;

	digits = count_digits(n, base);
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n / base)
		ft_putnbr_base(n / base, set, base);
	write(1, &set[n % base], 1);
	return (digits);
}

/*
int main(void)
{
	#include <stdio.h>
	printf("\n%d\n", ft_putnbr_base(4294967295, "0123456789", 10));
}
*/