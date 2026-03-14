/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:54:00 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 20:12:42 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

typedef struct	s_lengths
{
	size_t		core_len;
	size_t		digits_len;
	size_t		prec_zeros;
	size_t		pad_len;
}				t_lengths;

t_lengths	get_lengths(t_context *ctx, t_numfmt num);
size_t	get_nbaselen(unsigned long decimal, size_t base);
void	ft_putnbr_base(t_context *ctx, unsigned long n, char *digits);

void	number_printer(t_context *ctx, t_numfmt num)
{
	t_lengths	l;

	l = get_lengths(ctx, num);
	if(!(ctx->fmt.flags & F_MINUS) && !(ctx->fmt.flags & F_ZERO) && l.pad_len > 0)
		pf_putnchar(ctx, ' ', l.pad_len);
	if (num.sign)	
		pf_putstrn(ctx, num.sign, ft_strlen(num.sign));
	if (num.prefix)
		pf_putstrn(ctx, num.prefix, ft_strlen(num.prefix));
	if(ctx->fmt.flags & F_ZERO && l.pad_len > 0)
		pf_putnchar(ctx, '0', l.pad_len);
	if(ctx->fmt.flags & F_DOT)
		pf_putnchar(ctx, '0', l.prec_zeros);
	if (!((ctx->fmt.flags & F_DOT) && ctx->fmt.precision == 0 && num.value == 0))
		ft_putnbr_base(ctx, num.value, num.base);
	if (ctx->fmt.flags & F_MINUS && l.pad_len > 0)
		pf_putnchar(ctx, ' ', l.pad_len);
}

t_lengths	get_lengths(t_context *ctx, t_numfmt num)
{
	t_lengths	l;

	if(ctx->fmt.flags & F_DOT && ctx->fmt.precision == 0 && num.value == 0)
		l.digits_len = 0;
	else
		l.digits_len = get_nbaselen(num.value, ft_strlen(num.base));
	if (ctx->fmt.precision > l.digits_len)
		l.prec_zeros = ctx->fmt.precision - l.digits_len;
	else
		l.prec_zeros = 0;
	l.core_len = l.digits_len + l.prec_zeros;
	l.core_len += ft_strlen(num.sign) + ft_strlen(num.prefix);
	if (ctx->fmt.width > l.core_len)
		l.pad_len = ctx->fmt.width - l.core_len;
	else
		l.pad_len = 0;
	return (l);
}

size_t	get_nbaselen(unsigned long decimal, size_t base)
{
	size_t	n_len;

	n_len = 1;
	while(decimal >= base)
	{
		n_len++;
		decimal = decimal / base;
	}
	return(n_len);
}

void	ft_putnbr_base(t_context *ctx, unsigned long n, char *digits)
{
	unsigned long base;
	int	mod;

	base = ft_strlen(digits);
	mod = n % base;
	if (n >= base)
		ft_putnbr_base(ctx, n / base, digits);
	pf_putchar(ctx, digits[mod]);
}
