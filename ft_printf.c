/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:02:58 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/29 21:02:20 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_case(char *set, char c)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

int	put_case(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), "0123456789", 10));
	if (c == 'u')
		return (ft_putuint(va_arg(args, unsigned int), "0123456789", 10));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	if (c == 'x')
		return (ft_putuint(va_arg(args, unsigned int), "0123456789abcdef", 16));
	if (c == 'X')
		return (ft_putuint(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%' && check_case("cspdiuxX", *++s))
			count += put_case(*s++, args);
		else
			count += ft_putchar(*s++);
	}
	va_end(args);
	return (count);
}
/*
int main(void)
{
	#include <stdio.h>
	#include <limits.h>
	
	char *s = "hello";
	char c = '*';
	unsigned int u = 4294967295;
	int i = -2147483648;
	printf("\nTotal c: %d\n", ft_printf("%c", c));
	printf("\nTotal c: %d\n", printf("%c", c));

	printf("\nTotal s: %d\n", ft_printf("%s", s));
	printf("\nTotal s: %d\n", printf("%s", s));
	
	printf("\nTotal i: %d\n", ft_printf("%i", i));
	printf("\nTotal i: %d\n", printf("%i", i));

	printf("\nTotal d: %d\n", ft_printf("%d", i));
	printf("\nTotal d: %d\n", printf("%d", i));

	printf("\nTotal u: %d\n", ft_printf("%u", u));
	printf("\nTotal u: %d\n", printf("%u", u));

	printf("\nTotal x: %d\n", ft_printf("%x", -99));
	printf("\nTotal x: %d\n", printf("%x", -99));

	printf("\nTotal X: %d\n", ft_printf("%X", u));
	printf("\nTotal X: %d\n", printf("%X", u));

	printf("\nTotal p: %d\n", ft_printf("%p", LONG_MAX));
	printf("\nTotal p: %d\n", printf("%p", LONG_MAX));
	
	printf("\nTotal: %d\n", ft_printf("aa\n%c%u%iaa%%", c, u, i));
	printf("\nTotal: %d\n", printf("aa\n%c%u%iaa%%", c, u, i));
}
*/