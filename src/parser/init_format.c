/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:30:58 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/24 14:41:45 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_format(t_format *format)
{
	format->flag_minus = false;
	format->flag_zeros = false;
	format->flag_dot = false;
	format->flag_plus = false;
	format->flag_hash = false;
	format->flag_space = false;
	format->width = 0;
	format->precision = 0;
	format->specifier = '\0';
	format->len = 0;
}
