/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:46:24 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/16 20:58:23 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "spec_table.h"

void	handler_selector(t_context *ctx)
{
	const t_specifier	*g_spec_table;
	int					i;

	g_spec_table = get_spec_table();
	i = 0;
	while (g_spec_table[i].specifier)
	{
		if (g_spec_table[i].specifier == ctx->fmt.specifier)
		{
			ctx->fmt.flags &= g_spec_table[i].allowed_flags;
			priority_rules(&ctx->fmt);
			g_spec_table[i].handler(ctx);
			return ;
		}
		i++;
	}
}
