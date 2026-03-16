/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:15:17 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/16 20:59:55 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			init_context(t_context *ctx);
static const char	*process_token(t_context *ctx, const char *f);
static int			end_printer(t_context *ctx);

int	ft_printf(const char *format, ...)
{
	t_context	ctx;

	init_context(&ctx);
	va_start(ctx.args, format);
	format = process_token(&ctx, format);
	va_end(ctx.args);
	return (end_printer(&ctx));
}

static void	init_context(t_context *ctx)
{
	ctx->buff_pos = 0;
	ctx->total_len = 0;
	ctx->error = 0;
}

static const char	*process_token(t_context *ctx, const char *f)
{
	const char	*start;

	while (*f && !ctx->error)
	{
		start = f;
		if (*f == '%')
		{
			init_format(&ctx->fmt);
			f = format_parser((f + 1), &ctx->fmt);
			if (!ctx->fmt.specifier)
			{
				f = start;
				buf_char(ctx, *f);
				f++;
			}
			else
				handler_selector(ctx);
		}
		else
		{
			buf_char(ctx, *f);
			f++;
		}
	}
	return (f);
}

static int	end_printer(t_context *ctx)
{
	buf_flush(ctx);
	if (ctx->error)
		return (-1);
	else
		return ((int)ctx->total_len);
}
