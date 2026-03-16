/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:28:49 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/16 20:35:44 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	buf_char(t_context *ctx, char c)
{
	if (ctx->error)
		return ;
	if (ctx->buff_pos >= (size_t)PF_BUF_CAP)
		buf_flush(ctx);
	ctx->buffer[ctx->buff_pos] = c;
	ctx->buff_pos++;
}

void	buf_nchar(t_context *ctx, char c, size_t n)
{
	size_t	i;
	size_t	chunk;
	size_t	space;

	while (n > 0)
	{
		if (ctx->buff_pos == (size_t)PF_BUF_CAP)
			buf_flush(ctx);
		if (ctx->error)
			return ;
		chunk = n;
		space = (size_t)PF_BUF_CAP - ctx->buff_pos;
		if (chunk > space)
			chunk = space;
		i = 0;
		while (i < chunk)
		{
			ctx->buffer[ctx->buff_pos + i] = c;
			i++;
		}
		ctx->buff_pos += chunk;
		n -= chunk;
	}
}

void	buf_strn(t_context *ctx, const char *s, size_t n)
{
	size_t	i;
	size_t	chunk;
	size_t	space;

	while (n > 0)
	{
		if (ctx->buff_pos == (size_t)PF_BUF_CAP)
			buf_flush(ctx);
		if (ctx->error || !s)
			return ;
		chunk = n;
		space = (size_t)PF_BUF_CAP - ctx->buff_pos;
		if (chunk > space)
			chunk = space;
		i = 0;
		while (s && i < chunk)
		{
			ctx->buffer[ctx->buff_pos + i] = s[i];
			i++;
		}
		ctx->buff_pos += chunk;
		s += chunk;
		n -= chunk;
	}
}

void	buf_flush(t_context *ctx)
{
	ssize_t	w;
	size_t	i;
	size_t	remain;

	if (ctx->error || ctx->buff_pos == 0)
		return ;
	i = 0;
	while (i < ctx->buff_pos)
	{
		remain = ctx->buff_pos - i;
		w = write(1, ctx->buffer + i, remain);
		if (w < 1 || ctx->total_len > (size_t)INT_MAX - (size_t)w)
		{
			ctx->error = -1;
			return ;
		}
		ctx->total_len += (size_t)w;
		i += (size_t)w;
	}
	ctx->buff_pos = 0;
}
