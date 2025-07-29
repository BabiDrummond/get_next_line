/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:07:29 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/29 00:10:28 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long p)
{
	if (!p)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + \
			ft_putuint((unsigned int) p, "0123456789abcedf", 16));
}
