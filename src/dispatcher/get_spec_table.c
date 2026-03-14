/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spec_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:37:20 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 17:37:47 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const t_specifier	*get_spec_table(void)
{
	static const t_specifier	g_spec_table[] = {
	{'c', handler_c, F_MINUS},
	{'s', handler_s, F_MINUS | F_DOT},
	{'p', handler_p, F_MINUS},
	{'d', handler_di, F_MINUS | F_ZERO | F_DOT | F_PLUS | F_SPACE},
	{'i', handler_di, F_MINUS | F_ZERO | F_DOT | F_PLUS | F_SPACE},
	{'u', handler_u, F_MINUS | F_ZERO | F_DOT},
	{'x', handler_x, F_MINUS | F_ZERO | F_DOT | F_HASH},
	{'X', handler_x, F_MINUS | F_ZERO | F_DOT | F_HASH},
	{'%', handler_percent, 0},
	{0, NULL, 0}
	};

	return (g_spec_table);
}
