/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:30:58 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/09 21:30:04 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_format(t_format *format)
{
	format->flags = '\0';
	format->width = 0;
	format->precision = 0;
	format->specifier = '\0';
	format->len = 0;
}
