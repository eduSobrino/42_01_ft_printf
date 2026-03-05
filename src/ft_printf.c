/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:15:17 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/27 00:00:00 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
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
	// En caso de haber especificadores y argumentos
	va_start(args, format); 
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar_fd('%', 1);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) != '%')
		{
			t_format	curr_format;
			init_format(&curr_format);
			format = format_parser((char *)(format + 1), &curr_format);
			printer_selector(&args, &curr_format, specifier_printer_table);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
		}
	}
	va_end(args);	
	return (0);
}
