/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:46:24 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/23 19:43:03 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printer_selector(va_list *args, t_format *format, t_linker *table)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (table[i].specifier == format->specifier)
		{
			table[i].handler(args, format);
			return;
		}
		i++;
	}
}
