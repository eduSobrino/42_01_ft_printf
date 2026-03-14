/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:25:00 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/13 13:41:50 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

# define P_NULL "(nil)"

void	handler_p(t_context *ctx)
{
	unsigned long	p;
	t_numfmt		num;

	p = (unsigned long)va_arg(ctx->args, void*);
	if (!p)
	{
		if(!(ctx->fmt.flags & F_MINUS) && ctx->fmt.width > ft_strlen(P_NULL))
			padding(ctx->fmt.width, ft_strlen(P_NULL), ' ');
		ft_putstr_fd(P_NULL, 1);
		if((ctx->fmt.flags & F_MINUS) && ctx->fmt.width > ft_strlen(P_NULL))
			padding(ctx->fmt.width, ft_strlen(P_NULL), ' ');
		return ;
	}
	num.base = B_HEX_LOW;
	num.prefix = "0x";	
	num.sign = "\0";
	num.value = p;
	n_printer(ctx, num);
}
