/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_printer_lengths.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:44:25 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/15 20:45:25 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_PRINTER_LENGTHS_H
# define NUMBER_PRINTER_LENGTHS_H

# include <stddef.h>

typedef struct s_lengths
{
	size_t		core_len;
	size_t		digits_len;
	size_t		prec_zeros;
	size_t		pad_len;
}				t_lengths;

#endif
