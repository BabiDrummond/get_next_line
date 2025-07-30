/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:48:11 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/29 22:37:55 by bmoreira         ###   ########.fr       */
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

int	ft_putul(unsigned long n, char *set, int base)
{
	if (n / base)
		ft_putul(n / base, set, base);
	ft_putchar(set[n % base]);
	return (count_digits(n, base));
}
