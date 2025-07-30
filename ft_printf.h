/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:29:46 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/29 21:50:40 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n, char *set, int base);
int	ft_putul(unsigned long n, char *set, int base);
int	ft_putptr(unsigned long p);

#endif