/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:41:55 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/23 18:09:47 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex_fd(int n, int fd)
{
	int	len;

	len = 1;
	if (n / 16)
		ft_puthex_fd(n / 16, fd);
	if (n % 16 < 10)
		ft_putchar_fd(n % 16 + '0', fd);
	else
		ft_putchar_fd(n % 16 - 10 + 'a', fd);
	return (len);
}

int main(void)
{
	#include <stdio.h>
	//printf("%x", 10);
	ft_puthex_fd(16, 1);
	printf("\n%d\n", ft_puthex_fd(16, 1));
}