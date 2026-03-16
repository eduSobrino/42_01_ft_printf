/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number_sat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:02:57 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/16 20:03:18 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "parse_number_sat.h"

size_t	parse_number_sat(const char **p)
{
	size_t	n;
	size_t	d;

	n = 0;
	while (**p >= '0' && **p <= '9')
	{
		d = (size_t)(**p - '0');
		if (n > ((size_t)INT_MAX - d) / 10)
			n = INT_MAX;
		else
			n = n * 10 + d;
		(*p)++;
	}
	return (n);
}
