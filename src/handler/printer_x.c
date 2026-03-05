/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:57:02 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/27 01:00:25 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	get_hexlen(unsigned long decimal);
void	print_hex(unsigned long decimal, t_format *format, size_t len);
//void	put_hash(t_format *format);
//void	put_hex(unsigned long decimal, t_format *format);

void	printer_x(va_list *args, t_format *format)
{
	unsigned int	n;
	size_t			total_len;

	n = va_arg(*args, unsigned int);
	format->len = get_hexlen(n);
	if (format->precision > format->len)
		total_len = format->precision + (format->flag_hash * 2);
	else
		total_len = format->len + (format->flag_hash * 2);
	//Algoritmo de impresion
	print_hex(n, format, total_len);
}

size_t	get_hexlen(unsigned long decimal)
{
	size_t	n_len;

	n_len = 1;
	while(decimal >= 16)
	{
		n_len++;
		decimal = decimal / 16;
	}
	return(n_len);
}

void	print_hex(unsigned long decimal, t_format *format, size_t len)
{
	if (!format->flag_zeros && !format->flag_minus && format->width > len)
		padding(format->width, len, ' ');
	handle_hash_sign(decimal, format);
	if (format->flag_zeros && format->width > len)
		padding(format->width, len, '0');
	put_precision(format);
	ft_putnbr_base(decimal, "0123456789abcdef");
	if (format->flag_minus && format->width > len)
		padding(format->width, len, ' ');
}
/*
void	put_hash(t_format *format)
{
	if (format->flag_hash)
	{
		ft_putchar_fd('0', 1);
		if (format->specifier == 'X')
			ft_putchar_fd('X', 1);
		else
			ft_putchar_fd('x', 1);
	}
}
void	put_hex(unsigned long decimal, t_format *format)
{
	int	mod;

	mod = decimal % 16;
	if (decimal >= 16)
		put_hex(decimal / 16, format);
	if (mod >= 0 && mod <=9)
		ft_putchar_fd((mod) + '0', 1);
	else
	{
		if (format->specifier == 'X')
			ft_putchar_fd(ft_toupper(mod + 39 + '0'),1);
		else
			ft_putchar_fd(mod + 39 + '0',1);
	}
	format->len++;
}
*/
