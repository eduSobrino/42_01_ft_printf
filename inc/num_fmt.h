/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_fmt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:36:53 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/16 20:51:57 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_FMT_H
# define NUM_FMT_H

# include "libftprintf.h"

typedef struct s_numfmt
{
	unsigned long	value;
	char			*base;
	char			*sign;
	char			*prefix;
}					t_numfmt;

void	number_printer(t_context *ctx, t_numfmt num);

#endif
