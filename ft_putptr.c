/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:07:29 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/29 21:00:49 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n && ++len)
		n = n / base;
	return (len);
}

int	ft_putulong(unsigned long n, char *set, int base)
{
	if (n / base)
		ft_putulong(n / base, set, base);
	ft_putchar(set[n % base]);
	return (count_digits(n, base));
}

int	ft_putptr(unsigned long p)
{
	if (!p)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putulong(p, "0123456789abcedf", 16));
}
