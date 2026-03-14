/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:44:29 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/12 22:16:05 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdio.h> // for debugging
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include "libft.h"

# define F_MINUS	1
# define F_ZERO		2
# define F_HASH		4
# define F_SPACE	8
# define F_PLUS		16
# define F_DOT		32
# define B_DEC "0123456789"
# define B_HEX_LOW "0123456789abcdef"
# define B_HEX_UPP "0123456789ABCDEF"

/* -------------STRUCTURES--------------------------------------------------- */
typedef struct		s_format
{
	unsigned char	flags;
	size_t			width;
	size_t			precision;
	char			specifier;
	size_t			len;
}					t_format;

typedef struct		s_context
{
	va_list			args;
	size_t			total_len;
	t_format		fmt;
}					t_context;

typedef struct		s_specifier
{
	char			specifier;
	void			(*handler)(t_context *ctx);
	unsigned char	allowed_flags;
}					t_specifier;

typedef struct		s_numfmt
{
	unsigned long	value;
	char			*base;
	char			*sign;
	char			*prefix;
}					t_numfmt;

/* -----MAIN----------------------------------------------------------------- */
int		ft_printf(const char *format, ...);

/* -----PARSER--------------------------------------------------------------- */
void	init_format(t_format *fmt);
char   	*format_parser(char *format, t_format *curr_format);

/* -----DISPATCHER----------------------------------------------------------- */
void	handler_selector(t_context *ctx, t_specifier *table);
void    priority_rules(t_format *fmt);

/* -----HANDLER-------------------------------------------------------------- */
void	handler_c(t_context *ctx);
void	handler_s(t_context *ctx);
void	handler_p(t_context *ctx);
void	handler_di(t_context *ctx);
void	handler_u(t_context *ctx);
void	handler_x(t_context *ctx);
void	handler_percent(t_context *ctx);

/* -----UTILS---------------------------------------------------------------- */
size_t  get_nbaselen(unsigned long decimal, size_t base);
void	put_precision(t_format *fmt);
void   	padding(size_t width, size_t len, char flag);
void    ft_putnchar(char c, int n);
void    ft_putnbr_base(unsigned long n, char *digits);
void    n_printer(t_context *ctx, t_numfmt num);

#endif
