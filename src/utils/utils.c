/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:35:41 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 13:37:23 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_precision(t_format *format)
{
	padding(format->precision, format->len, '0');
}

void	padding(size_t width, size_t len, char flag)
{
	if (width > len)
		ft_putnchar(flag, width - len);
}

void	ft_putnchar(char c, int n)
{
	while (n > 0)
	{
		ft_putchar_fd(c, 1);
		n--;
	}
}
