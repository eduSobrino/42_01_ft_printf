/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:25:00 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 20:14:18 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

void	handler_x(t_context *ctx)
{
	unsigned int	x;
	t_numfmt		num;

	x = va_arg(ctx->args, unsigned int);
	num.sign = "\0";
	if (ctx->fmt.specifier == 'X')
	{
		num.base = B_HEX_UPP;
		if (ctx->fmt.flags & F_HASH)
			num.prefix = "0X";
		else
			num.prefix = "\0";
	}
	else
	{
		num.base = B_HEX_LOW;
		if (ctx->fmt.flags & F_HASH)
			num.prefix = "0x";
		else
			num.prefix = "\0";
	}
	if (x == 0)
		num.prefix = "\0";
	num.value = x;
	number_printer(ctx, num);
}
