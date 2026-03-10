/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:37:56 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/10 21:31:18 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_hex(unsigned long decimal, t_format *format, size_t len);

void	printer_p(t_context *ctx)
{
	unsigned long	p;
	size_t			total_len;

	p = (unsigned long)va_arg(ctx->args, void *);
	ctx->fmt.flag_hash = true;
	ctx->fmt.len = get_nbaselen(p, 16);
	total_len = ctx->fmt.flag_hash * 2 + ctx->fmt.len;
	print_hex(p, &ctx->fmt, total_len);
}
