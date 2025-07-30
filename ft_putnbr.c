/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:48:11 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/29 22:37:48 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0 && ++len)
		n *= -1;
	while (n && ++len)
		n = n / base;
	return (len);
}

int	ft_putnbr(int n, char *set, int base)
{
	int	digits;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	digits = count_digits(n, base);
	if (n < 0 && ft_putchar('-'))
		n *= -1;
	if (n / base)
		ft_putnbr(n / base, set, base);
	ft_putchar(set[n % base]);
	return (digits);
}
