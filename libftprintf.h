/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:44:29 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/04 21:23:45 by esobrino         ###   ########.fr       */
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

/* -------------STRUCTURES--------------------------------------------------- */
typedef struct	s_format
{
	bool		flag_minus;
	bool		flag_zeros;
	bool		flag_dot;
	bool		flag_plus;
	bool		flag_hash;
	bool		flag_space;
	size_t		width;
	size_t		precision;
	char		specifier;
	size_t		len;
}				t_format;

typedef struct	s_linker
{
	char		specifier;
	void		(*handler)(va_list *args, t_format *format);
}				t_linker;

/* -----MAIN----------------------------------------------------------------- */
int		ft_printf(const char *format, ...);

/* -----PARSER--------------------------------------------------------------- */
void	init_format(t_format *format);
char   	*format_parser(char *format, t_format *curr_format);

/* -----HANDLER-------------------------------------------------------------- */
void   	printer_selector(va_list *args, t_format *format, t_linker *table);
void   	printer_c(va_list *args, t_format *format);
void   	printer_s(va_list *args, t_format *format);
void   	printer_p(va_list *args, t_format *format);
void   	printer_di(va_list *args, t_format *format);
void   	printer_u(va_list *args, t_format *format);
void   	printer_x(va_list *args, t_format *format);

/* -----UTILS---------------------------------------------------------------- */
size_t  get_nbaselen(unsigned long decimal, size_t base);
void    handle_hash_sign(int n, t_format *format);
void	put_precision(t_format *format);
void   	padding(size_t width, size_t len, char flag);
void    ft_putnchar(char c, int n);
void    ft_putnbr_base(unsigned long n, char *digits);

#endif
