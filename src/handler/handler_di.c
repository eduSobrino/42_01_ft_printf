/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:11:59 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 20:13:41 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

void	handler_di(t_context *ctx)
{
	long		di;
	t_numfmt	num;

	di = (long)va_arg(ctx->args, int);
	num.base = B_DEC;
	num.sign = "\0";
	if (di < 0)
	{
		num.sign = "-";
		di = -di;
	}
	else
	{
		if(ctx->fmt.flags & F_PLUS)
			num.sign = "+";
		else if(ctx->fmt.flags & F_SPACE)
			num.sign = " ";
	}
	num.prefix = "\0";
	num.value = di;
	number_printer(ctx, num);
}
