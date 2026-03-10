/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:57:02 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/10 21:34:44 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	get_hexlen(unsigned long decimal);
void	print_hex(unsigned long decimal, t_format *format, size_t len);

void	printer_x(t_context *ctx)
{
	unsigned int	n;
	size_t			total_len;

	n = va_arg(ctx->args, unsigned int);
	ctx->fmt.len = get_hexlen(n);
	if (ctx->fmt.precision > ctx->fmt.len)
		total_len = ctx->fmt.precision + (ctx->fmt.flag_hash * 2);
	else
		total_len = ctx->fmt.len + (ctx->fmt.flag_hash * 2);
	print_hex(n, &ctx->fmt, total_len);
}

size_t	get_hexlen(unsigned long decimal)
{
	size_t	n_len;

	n_len = 1;
	while (decimal >= 16)
	{
		n_len++;
		decimal = decimal / 16;
	}
	return (n_len);
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
