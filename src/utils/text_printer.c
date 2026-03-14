/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 20:15:03 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 20:55:00 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	text_printer(t_context *ctx, const char *buf, size_t len)
{
	size_t	pad_len;

	pad_len = 0;
	if (ctx->fmt.width > len)
		pad_len = ctx->fmt.width - len;
	if (!(ctx->fmt.flags & F_MINUS) && pad_len)
		pf_putnchar(ctx, ' ', pad_len);
	pf_putstrn(ctx, buf, len);
	if (ctx->fmt.flags & F_MINUS && pad_len)
		pf_putnchar(ctx, ' ', pad_len);
}
