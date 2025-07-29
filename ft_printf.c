/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:02:58 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/29 00:10:23 by bmoreira         ###   ########.fr       */
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

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}
// int	put_case(char *s, va_list args)
// {
// 	while (*s)
// 	{
// 		if (*s == '%' && *(s + 1) == '%' && s++)
// 			ft_putchar(*s);
// 		if (*s == '%' && *(s + 1) == 'c' && s++)
// 			ft_putchar(va_arg(args, int));
// 		if (*s == '%' && *(s + 1) == 's' && s++)
// 			ft_putstr(va_arg(args, char *));
// 		if (*s == '%' && (*(s + 1) == 'd' || *(s + 1) == 'i') && s++)
// 			ft_putnbr(va_arg(args, int), "0123456789", 10);
// 		if (*s == '%' && *(s + 1) == 'u' && s++)
// 			ft_putuint(va_arg(args, unsigned int), "0123456789", 10);
// 		if (*s == '%' && *(s + 1) == 'p' && s++)
// 			ft_putptr(va_arg(args, unsigned long long));
// 		if (*s == '%' && *(s + 1) == 'x' && s++)
// 			ft_putuint(va_arg(args, unsigned int), "0123456789abcedf", 16);
// 		if (*s == '%' && *(s + 1) == 'X' && s++)
// 			ft_putuint(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
// 		else
// 			ft_putchar(*s++);
// 		s++;
// 	}
// 	return (0);
// }

int	put_case(char c, void *p)
{
	if (c == 'c')
		return (ft_putchar((int)(long) p));
	if (c == 's')
		return (ft_putstr((char *) p));
	if (c == 'd' || c == 'i')
		return (ft_putnbr((int)(long) p, "0123456789", 10));
	if (c == 'u')
		return (ft_putuint((unsigned int)(unsigned long) p, "0123456789", 10));
	if (c == 'p')
		return (ft_putptr((unsigned long long) p));
	if (c == 'x')
		return (ft_putuint((unsigned int)
				(unsigned long) p, "0123456789abcedf", 16));
	if (c == 'X')
		return (ft_putuint((unsigned int)
				(unsigned long) p, "0123456789ABCDEF", 16));
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
		if (*s == '%' && check_case("csdiupxX", *++s))
			count += put_case(*s++, va_arg(args, void *));
		else
			count += ft_putchar(*s++);
	}
	va_end(args);
	return (count);
}
/*
int main(void)
{
	char c = 'o';
	unsigned int u = 34231;
	int i = -23;
	ft_printf("aa\n%c%u%iaa%%%\n", c, u, i);
}
*/