/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:53:20 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/24 20:48:17 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_flags(char *format, t_format *curr_format);
char	*get_width(char *format, t_format *curr_format);
char	*get_precision(char *format, t_format *curr_format);
char	*get_specifier(char *format, t_format *curr_format);

char	*format_parser(char *format, t_format *curr_format)
{
	// Get [flag]
	format = get_flags(format, curr_format);
	// Get [width] 
	format = get_width(format, curr_format);
	// Get .[precision]
	format = get_precision(format, curr_format);
	// Get Specifier
	format = get_specifier(format, curr_format);
	return (format);
}

char	*get_flags(char *format, t_format *curr_format)
{
	char	flags[6] = "-0# +";

	while (ft_strchr(flags, *format) && *format != '\0')
	{
		if (*format == '-')
			curr_format->flag_minus = true;
		else if (*format == '0')
			curr_format->flag_zeros = true;
		else if (*format == '+')
			curr_format->flag_plus = true;
		else if (*format == ' ')
			curr_format->flag_space = true;
		else if (*format == '#')
			curr_format->flag_hash = true;
		format++;
	}
	return (format);
}

char	*get_width(char *format, t_format *curr_format)
{
	while (*format >= '0' && *format <= '9')
	{
		curr_format->width = curr_format->width * 10 + (*format - '0');
		format++;
	}
	return (format);
}

char	*get_precision(char *format, t_format *curr_format)
{
	if (*format == '.')
	{
		curr_format->flag_dot = true;
		format++;
		while (*format >= '0' && *format <= '9')
		{
			curr_format->precision = curr_format->precision * 10 + (*format - '0');
			format++;
		}
	}
	return (format);
}

char	*get_specifier(char *format, t_format *curr_format)
{
	char	specifiers[10] = "cspdiuxX%";

	if (ft_strchr(specifiers, *format))
	{
		curr_format->specifier = *format;
		format++;
	}
	return (format);
}
