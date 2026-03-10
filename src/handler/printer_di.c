/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:03:05 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/10 21:30:39 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_di(int n, t_format *format, size_t len);

void	printer_di(t_context *ctx)
{
	int		di;
	size_t	total_len;

	di = va_arg(ctx->args, int);
	ctx->fmt.len = get_nbaselen(di, 10);
	if (ctx->fmt.precision > ctx->fmt.len)
		total_len = ctx->fmt.precision + ctx->fmt.flag_plus + ctx->fmt.flag_space;
	else
		total_len = ctx->fmt.len + ctx->fmt.flag_plus + ctx->fmt.flag_space;
	put_di(di, &ctx->fmt, total_len);
}

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
