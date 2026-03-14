/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:30:58 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 20:34:16 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_format(t_format *fmt)
{
	fmt->flags = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->specifier = '\0';
}
