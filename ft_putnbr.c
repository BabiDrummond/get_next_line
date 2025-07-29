/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:48:11 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/29 00:10:20 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putnbr(int n, char *set, int base)
{
	int	digits;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	digits = count_digits(n, base);
	if (n < 0 && write(1, "-", 1))
		n *= -1;
	if (n / base)
		ft_putnbr(n / base, set, base);
	write(1, &set[n % base], 1);
	return (digits);
}

/*
int main(void)
{
	#include <stdio.h>
	printf("\n%d\n", ft_putnbr(2147483647, "0123456789abcdef", 10));
}
*/