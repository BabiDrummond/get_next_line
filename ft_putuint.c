/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:48:11 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/29 00:10:16 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int	ft_putuint(unsigned int n, char *set, int base)
{
	int	digits;

	digits = count_digits(n, base);
	if (n / base)
		ft_putuint(n / base, set, base);
	write(1, &set[n % base], 1);
	return (digits);
}

/*
int main(void)
{
	#include <stdio.h>
	printf("\n%d\n", ft_putuint(4294967295, "0123456789abcdef", 16));
}
*/