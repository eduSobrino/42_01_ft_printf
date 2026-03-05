/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:00:28 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/27 00:16:42 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    put_char(char c, t_format *format);

void	printer_c(va_list *args, t_format *format)
{
	char	c;

	c = (char)va_arg(*args,int);
	format->len = 1;
	put_char(c, format);
}

void	put_char(char c, t_format *format)
{
	if (format->flag_minus && format->width > format->len)
	{
		ft_putchar_fd(c, 1);
		padding(format->width, format->len, ' ');
	}
	else 
	{
		padding(format->width, format->len, ' ');
		ft_putchar_fd(c, 1);
	}
}
