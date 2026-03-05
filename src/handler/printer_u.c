/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:17:31 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/27 00:58:28 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//size_t	get_unbrlen(unsigned int decimal);
void	print_unbr(int n, t_format *format, size_t len);
//void	put_unbr(unsigned int n);

void	printer_u(va_list *args, t_format *format)
{
	unsigned int	unbr;
	size_t			total_len;

	unbr = va_arg(*args, unsigned int);
	format->len = get_nbaselen(unbr, 10);
	if (format->precision > format->len)
		total_len = format->precision + format->flag_plus + format->flag_space;
	else
		total_len = format->len + format->flag_plus + format->flag_space;
	print_unbr(unbr, format, total_len);
}
/*
size_t	get_unbrlen(unsigned int decimal)
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
void	print_unbr(int n, t_format *format, size_t len)
{
	if (!format->flag_zeros && !format->flag_minus && format->width > len)
		padding(format->width, len, ' ');
	if (format->flag_zeros && format->width > len)
		padding(format->width, len, '0');
	put_precision(format);
	ft_putnbr_base(n, "0123456789");	
	if (format->flag_minus && format->width > len)
		padding(format->width, len, ' ');
}
/*
void	put_unbr(unsigned int n)
{
	if (n >= 10)
		put_unbr(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}
*/
