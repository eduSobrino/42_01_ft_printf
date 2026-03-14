/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:15:17 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 19:58:57 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	t_context	ctx;
	const char	*parser_start;

	ctx.total_len = 0;
	va_start(ctx.args, format); 
	while (*format)
	{
		parser_start = format;
		if (*format == '%')
		{
			init_format(&ctx.fmt);
			format = format_parser((format + 1), &ctx.fmt);
			if (!ctx.fmt.specifier)
			{
				format = parser_start;
				pf_putchar(&ctx, *format);
				format++;
			}
			else 
				handler_selector(&ctx);
		}
		else
		{
			pf_putchar(&ctx, *format);
			format++;
		}
	}
	va_end(ctx.args);	
	return (ctx.total_len);
}
