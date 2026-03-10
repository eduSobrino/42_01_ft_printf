/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:07:34 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/10 21:31:58 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_str(char *s, t_format *format);
void	put_nstr(char *s, size_t n);

void	printer_s(t_context *ctx)
{
	char	*s;

	s = va_arg(ctx->args, char *);
	ctx->fmt.len = ft_strlen(s);
	if (ctx->fmt.precision < ctx->fmt.len)
		ctx->fmt.len = ctx->fmt.precision;
	print_str(s, &ctx->fmt);
}

void	print_str(char *s, t_format *format)
{
	if (format->flag_minus && format->width > format->len)
	{
		put_nstr(s, format->len);
		padding(format->width, format->len, ' ');
	}
	else
	{
		padding(format->width, format->len, ' ');
		put_nstr(s, format->len);
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
