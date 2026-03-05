/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:03:05 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/27 00:57:01 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//size_t	get_nlen(int decimal);
void	put_di(int n, t_format *format, size_t len);
//void	put_sign(int n, t_format *format);
//void	put_nbr(int n);

void	printer_di(va_list *args, t_format *format)
{
	int	di;
	size_t	total_len;

	di = va_arg(*args, int);
	format->len = get_nbaselen(di, 10);
	if (format->precision > format->len)
		total_len = format->precision + format->flag_plus + format->flag_space;
	else
		total_len = format->len + format->flag_plus + format->flag_space;
	put_di(di, format, total_len);
}
/*
size_t	get_nlen(int decimal)
{
	size_t	n_len;

	n_len = 1;
	while(decimal >= 10)
	{
		n_len++;
		decimal = decimal / 10;
	}
	return(n_len);
}
*/
void	put_di(int n, t_format *format, size_t len)
{
	if (!format->flag_zeros && !format->flag_minus && format->width > len)
		padding(format->width, len, ' ');
	handle_hash_sign(n, format);
	if (format->flag_zeros && format->width > len)
		padding(format->width, len, '0');
	put_precision(format);
	ft_putnbr_base(n, "0123456789");
	if (format->flag_minus && format->width > len)
		padding(format->width, len, ' ');
}
/*
void	put_sign(int n, t_format *format)
{
	if (n > 0)
	{
		if (format->flag_plus)
			ft_putchar_fd(43, 1);
		else if (format->flag_space)
			ft_putchar_fd(32, 1);
	}
	if (n < 0)
		ft_putchar_fd(45, 1);
}

void	put_nbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, 1);
	ft_putchar_fd((nb % 10) + '0', 1);
}
*/
