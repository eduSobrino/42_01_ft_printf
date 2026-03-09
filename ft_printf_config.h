/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_config.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:01:50 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/09 22:01:02 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONFIG_H
# define FT_PRINTF_CONFIG_H

/*
 * X-Macro: the 'source of truth' for the specifiers
 * Format: MAPPER(character, handler) 
 */

# define SPECIFIERS_LIST \
	MAPPER('c', printer_c)	\
	MAPPER('s', printer_s)	\
	MAPPER('p', printer_p)	\
	MAPPER('d', printer_di)	\
	MAPPER('i', printer_di)	\
	MAPPER('u', printer_u)	\
	MAPPER('x', printer_x)	\
	MAPPER('X', printer_x)	\
	MAPPER('%', printer_percent)

/*
 * X-Macro and Bitmask Flags
 */
# define FLAGS_LIST \
	FLAG('-', F_MINUS)	\
	FLAG('0', F_ZERO)	\
	FLAG('#', F_HASH)	\
	FLAG(' ', F_SPACE)	\
	FLAG('+', F_PLUS)	\

# define F_MINUS	(1 << 0) // 1
# define F_ZERO		(1 << 1) // 2
# define F_HASH		(1 << 2) // 4
# define F_SPACE	(1 << 3) // 8
# define F_PLUS		(1 << 4) // 16
# define F_DOT		(1 << 5) // 32

#endif
