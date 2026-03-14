/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:46:24 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/12 20:58:03 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handler_selector(t_context *ctx, t_specifier *table)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (table[i].specifier == ctx->fmt.specifier)
		{
			ctx->fmt.flags &= table[i].allowed_flags;
			priority_rules(&ctx->fmt);
			table[i].handler(ctx);
			return ;
		}
		i++;
	}
}
