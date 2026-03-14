/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:00:28 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/12 20:56:36 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_char(char c, t_format *fmt);

void	handler_c(t_context *ctx)
{
	char	c;

	c = (char)va_arg(ctx->args, int);
	ctx->fmt.len = 1;
	put_char(c, &ctx->fmt);
}

void	put_char(char c, t_format *fmt)
{
	if (fmt->flags & F_MINUS && fmt->width > fmt->len)
	{
		ft_putchar_fd(c, 1);
		padding(fmt->width, fmt->len, ' ');
	}
	else
	{
		padding(fmt->width, fmt->len, ' ');
		ft_putchar_fd(c, 1);
	}
}
