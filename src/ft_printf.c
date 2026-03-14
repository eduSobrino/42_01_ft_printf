/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:15:17 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/12 21:19:38 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	t_context	ctx;

	t_specifier	specifier_table[] = 
	{
		{'c', handler_c, F_MINUS}, 
		{'s', handler_s, F_MINUS | F_DOT}, 
		{'p', handler_p, F_MINUS}, 
		{'d', handler_di, F_MINUS | F_ZERO | F_DOT | F_PLUS | F_SPACE}, 
		{'i', handler_di, F_MINUS | F_ZERO | F_DOT | F_PLUS | F_SPACE}, 
		{'u', handler_u, F_MINUS | F_ZERO | F_DOT}, 
		{'x', handler_x, F_MINUS | F_ZERO | F_DOT | F_HASH}, 
		{'X', handler_x, F_MINUS | F_ZERO | F_DOT | F_HASH},
		{'%', handler_percent, 0} 
	};
	ctx.total_len = 0;
	va_start(ctx.args, format); 
	while (*format)
	{
		if (*format == '%')
		{
			init_format(&ctx.fmt);
			format = format_parser((char *)(format + 1), &ctx.fmt);
			handler_selector(&ctx, specifier_table);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
		}
	}
	va_end(ctx.args);	
	return (ctx.total_len);
}
