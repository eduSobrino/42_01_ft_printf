/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:53:20 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/09 22:01:50 by esobrino         ###   ########.fr       */
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
# define FLAG_LIST(c, f) c, 
	static const char	all_flags = { LIST_FLAGS 0 };
# undef FLAG_LIST

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
		curr_format->flags |= F_DOT;
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
# define MAPPER(c, f) c, 
	static const char	specifiers[] = {SPECIFIERS_LIST 0};
#undef MAPPER

	if (ft_strchr(specifiers, *format))
	{
		curr_format->specifier = *format;
		format++;
	}
	return (format);
}
