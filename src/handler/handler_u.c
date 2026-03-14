/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:42:48 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/12 22:23:01 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

void	handler_u(t_context *ctx)
{
	unsigned int	u;
	t_numfmt		num;

	u = va_arg(ctx->args, unsigned int);
	num.base = B_DEC;
	num.sign = "\0";
	num.prefix = "\0";
	num.value = u;
	n_printer(ctx, num);
}
