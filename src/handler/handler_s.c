/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:07:34 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/13 10:58:59 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_str(char *s, t_format *fmt);
void	put_nstr(char *s, size_t n);

void	handler_s(t_context *ctx)
{
	char	*s;

	s = va_arg(ctx->args, char *);
	if (!s)
		s = "(null)";
	ctx->fmt.len = ft_strlen(s);
	if (ctx->fmt.flags & F_DOT && ctx->fmt.precision < ctx->fmt.len)
		ctx->fmt.len = ctx->fmt.precision;
	print_str(s, &ctx->fmt);
}

void	print_str(char *s, t_format *fmt)
{
	if (fmt->flags & F_MINUS && fmt->width > fmt->len)
	{
		put_nstr(s, fmt->len);
		padding(fmt->width, fmt->len, ' ');
	}
	else
	{
		padding(fmt->width, fmt->len, ' ');
		put_nstr(s, fmt->len);
	}
}

void	put_nstr(char *s, size_t n)
{
	size_t	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (i < n && s[i] != '\0')
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}
