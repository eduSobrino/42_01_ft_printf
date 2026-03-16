/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:55:27 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/16 20:56:11 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPEC_TABLE_H
# define SPEC_TABLE_H

# include "libftprintf.h"

typedef struct s_specifier
{
	char			specifier;
	void			(*handler)(t_context *ctx);
	unsigned char	allowed_flags;
}					t_specifier;

const t_specifier	*get_spec_table(void);

#endif
