/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:25:00 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 20:13:57 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

# define P_NULL "(nil)"

void	handler_p(t_context *ctx)
{
	unsigned long	p;
	t_numfmt		num;
	size_t			pad_len;

	p = (unsigned long)va_arg(ctx->args, void*);
	if (!p)
	{
		pad_len = 0;
		if (ctx->fmt.width > ft_strlen(P_NULL))
			pad_len = ctx->fmt.width - ft_strlen(P_NULL);
		if(!(ctx->fmt.flags & F_MINUS) && pad_len)
			pf_putnchar(ctx, ' ', pad_len);
		pf_putstrn(ctx, P_NULL, ft_strlen(P_NULL));
		if((ctx->fmt.flags & F_MINUS) && pad_len)
			pf_putnchar(ctx, ' ', pad_len);
		return ;
	}
	num.base = B_HEX_LOW;
	num.prefix = "0x";	
	num.sign = "\0";
	num.value = p;
	number_printer(ctx, num);
}
