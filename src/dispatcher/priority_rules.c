/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:44:26 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/15 19:03:16 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	priority_rules(t_format *fmt)
{
	if (fmt->flags & F_MINUS)
		fmt->flags &= ~F_ZERO;
	if (fmt->flags & F_PLUS)
		fmt->flags &= ~F_SPACE;
	if ((fmt->flags & F_DOT)
		&& (fmt->specifier == 'd' || fmt->specifier == 'i'
			|| fmt->specifier == 'u' || fmt->specifier == 'x'
			|| fmt->specifier == 'X'))
		fmt->flags &= ~F_ZERO;
}
