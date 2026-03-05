/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:07:34 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/27 00:17:25 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_str(char *s, t_format *format);
void	put_nstr(char *s, size_t n);

void	printer_s(va_list *args, t_format *format)
{
	char	*s;

	s = va_arg(*args, char *);
	format->len = ft_strlen(s);
	if (format->precision < format->len)
		format->len = format->precision;
	print_str(s, format);
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
