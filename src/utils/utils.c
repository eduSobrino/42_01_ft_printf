/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:35:41 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/04 21:24:36 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	get_nbaselen(unsigned long decimal, size_t base)
{
	size_t	n_len;

	n_len = 1;
	while(decimal >= base)
	{
		n_len++;
		decimal = decimal / base;
	}
	return(n_len);
}

void	handle_hash_sign(int n, t_format *format)
{
	if (format->flag_hash)
	{
		ft_putchar_fd('0', 1);
		if (format->specifier == 'X')
			ft_putchar_fd('X', 1);
		else
			ft_putchar_fd('x', 1);
	}
	if (n > 0 && !format->flag_hash)
	{
		if (format->flag_plus)
			ft_putchar_fd(43, 1);
		else if (format->flag_space)
			ft_putchar_fd(32, 1);
	}
	else if (n < 0 && !format->flag_hash)
		ft_putchar_fd(45, 1);
}

void	put_precision(t_format *format)
{
	padding(format->precision, format->len, '0');
}

void	padding(size_t width, size_t len, char flag)
{
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

void	ft_putnbr_base(unsigned long n, char *digits)
{
	unsigned long base;
	int	mod;

	base = ft_strlen(digits);
	mod = n % base;
	if (n >= base)
		ft_putnbr_base(n / base, digits);
	ft_putchar_fd(digits[mod], 1);
}
