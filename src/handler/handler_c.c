/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:00:28 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 20:46:51 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handler_c(t_context *ctx)
{
	char	c;

	c = (char)va_arg(ctx->args, int);
	text_printer(ctx, &c, 1);
}
