/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:15:17 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/10 21:25:54 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	t_context	ctx;

	t_linker	specifier_printer_table[] = 
	{
		{'c', printer_c}, 
		{'s', printer_s}, 
		{'p', printer_p}, 
		{'d', printer_di}, 
		{'i', printer_di}, 
		{'u', printer_u}, 
		{'x', printer_x}, 
		{'X', printer_x} 
	};
	ctx.total_len = 0;
	va_start(ctx.args, format); 
	while (*format)
	{
		if (*format == '%')
		{
			init_format(&ctx.fmt);
			format = format_parser((char *)(format + 1), &ctx.fmt);
			printer_selector(&ctx, specifier_printer_table);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
		}
	}
	va_end(ctx.args);	
	return (0);
}
