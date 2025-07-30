/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:07:29 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/29 21:50:22 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long p)
{
	if (!p)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putul(p, "0123456789abcedf", 16));
}
