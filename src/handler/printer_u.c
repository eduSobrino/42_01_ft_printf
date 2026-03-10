/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:17:31 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/10 21:33:57 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_unbr(int n, t_format *format, size_t len);

void	printer_u(t_context *ctx)
{
	unsigned int	unbr;
	size_t			total_len;

	unbr = va_arg(ctx->args, unsigned int);
	ctx->fmt.len = get_nbaselen(unbr, 10);
	if (ctx->fmt.precision > ctx->fmt.len)
		total_len = ctx->fmt.precision + ctx->fmt.flag_plus + ctx->fmt.flag_space;
	else
		total_len = ctx->fmt.len + ctx->fmt.flag_plus + ctx->fmt.flag_space;
	print_unbr(unbr, &ctx->fmt, total_len);
}

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
