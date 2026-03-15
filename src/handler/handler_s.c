/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:07:34 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/15 19:03:57 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handler_s(t_context *ctx)
{
	char	*s;
	size_t	s_len;

	s = va_arg(ctx->args, char *);
	if (!s)
		s = "(null)";
	s_len = ft_strlen(s);
	if (ctx->fmt.flags & F_DOT && ctx->fmt.precision < s_len)
		s_len = ctx->fmt.precision;
	text_printer(ctx, s, s_len);
}
