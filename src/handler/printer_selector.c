/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:46:24 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/10 21:37:19 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printer_selector(t_context *ctx, t_linker *table)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (table[i].specifier == ctx->fmt.specifier)
		{
			table[i].handler(ctx);
			return ;
		}
		i++;
	}
}
