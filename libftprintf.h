/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:44:29 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/16 20:56:46 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>
# include "libft.h"

# define PF_BUF_CAP 4096
# define FP_FLAGS	"-0# +"
# define FP_DOT		'.'
# define F_MINUS	1
# define F_ZERO		2
# define F_HASH		4
# define F_SPACE	8
# define F_PLUS		16
# define F_DOT		32
# define B_DEC 		"0123456789"
# define B_HEX_LOW 	"0123456789abcdef"
# define B_HEX_UPP 	"0123456789ABCDEF"

/* -------------STRUCTURES--------------------------------------------------- */
typedef struct s_format
{
	unsigned char	flags;
	size_t			width;
	size_t			precision;
	char			specifier;
}					t_format;

typedef struct s_context
{
	va_list			args;
	char			buffer[PF_BUF_CAP];
	size_t			buff_pos;
	size_t			total_len;
	int				error;
	t_format		fmt;
}					t_context;

/* -----MAIN----------------------------------------------------------------- */
int					ft_printf(const char *format, ...);

/* -----PARSER--------------------------------------------------------------- */
void				init_format(t_format *fmt);
const char			*format_parser(const char *format, t_format *fmt);

/* -----DISPATCHER----------------------------------------------------------- */
void				handler_selector(t_context *ctx);
void				priority_rules(t_format *fmt);

/* -----HANDLER-------------------------------------------------------------- */
void				handler_c(t_context *ctx);
void				handler_s(t_context *ctx);
void				handler_p(t_context *ctx);
void				handler_di(t_context *ctx);
void				handler_u(t_context *ctx);
void				handler_x(t_context *ctx);
void				handler_percent(t_context *ctx);

/* -----UTILS---------------------------------------------------------------- */
void				text_printer(t_context *ctx, const char *buf, size_t len);
void				buf_char(t_context *ctx, char c);
void				buf_nchar(t_context *ctx, char c, size_t n);
void				buf_strn(t_context *ctx, const char *s, size_t n);
void				buf_flush(t_context *ctx);

#endif
