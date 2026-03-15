/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:53:20 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/15 20:08:19 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static const char	*get_flags(const char *format, t_format *fmt);
static const char	*get_width(const char *format, t_format *fmt);
static const char	*get_precision(const char *format, t_format *fmt);
static const char	*get_specifier(const char *format, t_format *fmt);

const char	*format_parser(const char *format, t_format *fmt)
{
	format = get_flags(format, fmt);
	format = get_width(format, fmt);
	format = get_precision(format, fmt);
	format = get_specifier(format, fmt);
	return (format);
}

static const char	*get_flags(const char *format, t_format *fmt)
{
	while (ft_strchr(FP_FLAGS, *format) && *format != '\0')
	{
		if (*format == '-')
			fmt->flags |= F_MINUS;
		else if (*format == '0')
			fmt->flags |= F_ZERO;
		else if (*format == '+')
			fmt->flags |= F_PLUS;
		else if (*format == ' ')
			fmt->flags |= F_SPACE;
		else if (*format == '#')
			fmt->flags |= F_HASH;
		format++;
	}
	return (format);
}

static const char	*get_width(const char *format, t_format *fmt)
{
	while (*format >= '0' && *format <= '9')
	{
		fmt->width = fmt->width * 10 + (*format - '0');
		format++;
	}
	return (format);
}

static const char	*get_precision(const char *format, t_format *fmt)
{
	if (*format == FP_DOT)
	{
		fmt->flags |= F_DOT;
		format++;
		while (*format >= '0' && *format <= '9')
		{
			fmt->precision = fmt->precision * 10 + (*format - '0');
			format++;
		}
	}
	return (format);
}

static const char	*get_specifier(const char *format, t_format *fmt)
{
	const t_specifier	*table;
	int					i;

	if (!*format)
		return (format);
	table = get_spec_table();
	i = 0;
	while (table[i].specifier)
	{
		if (table[i].specifier == *format)
		{
			fmt->specifier = *format;
			format++;
			return (format);
		}
		i++;
	}
	return (format);
}
