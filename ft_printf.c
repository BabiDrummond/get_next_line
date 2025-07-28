/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:02:58 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/28 19:36:10 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	case_print(char *s, va_list args)
{
	while (*s)
	{
		if (*s++ == '%')
		{
			if (*s == 'c' || *s == 's')
				ft_putstr(va_arg(args, char *));
			if (*s == 'p')
				ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcedf", 16);
			if (*s == 'd' || *s == 'i')
				ft_putnbr_base(va_arg(args, int), "0123456789", 10);
			if (*s == 'u')
				ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10);
			if (*s == 'x')
				ft_putnbr_base(va_arg(args, int), "0123456789abcedf", 16);
			if (*s == 'X')
				ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 16);
			if (*s == '%')
				write (1, '%', 1);
		}
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;

	va_start(args, s);
	case_print(s, args);
	va_end(args);
	return (0);
}
