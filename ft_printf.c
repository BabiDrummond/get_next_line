/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:02:58 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/27 23:13:57 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	case_print(char *s)
{
	while (*s)
	{
		if (*s++ == '%')
		{
			if (*s == 'c')
				write(fd, s, 1);
			else if (*s == 's')
				ft_putstr_fd(s, fd);
			else if (*s == 'p')
				ft_putpt_fd(s, fd);
			else if (*s == 'd')
				ft_putnbr_base_fd(s, "0123456789", 10, fd);
			else if (*s == 'i')
				ft_putnbr_base_fd(s, "0123456789", 10, fd);
			else if (*s == 'u')
			else if (*s == 'x')
				ft_putnbr_base_fd(s, "0123456789", 10, fd);
			else if (*s == 'X')
				ft_putnbr_base_fd(s, "0123456789", 10, fd);
			else if (*s == '%')
				write (fd, '%', 1);
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	va_arg(args, char *);
	va_arg(args, int);
	va_arg(args, unsigned int);
	va_end(args);
	return (0);
}
