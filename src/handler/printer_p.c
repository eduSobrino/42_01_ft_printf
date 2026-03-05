/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:37:56 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/26 23:58:21 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//size_t	get_hexlen(unsigned long decimal);
void	print_hex(unsigned long decimal, t_format *format, size_t len);

void	printer_p(va_list *args, t_format *format)
{
	unsigned long	p;
	size_t			total_len;

	p = (unsigned long)va_arg(*args, void *);
	format->flag_hash = true;
	format->len = get_nbaselen(p, 16);
	total_len = format->flag_hash * 2 + format->len;
	print_hex(p, format, total_len);
}
