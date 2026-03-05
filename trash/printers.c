/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:55:13 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/24 23:12:37 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    print_hex(unsigned long decimal, t_format *format, size_t len);
void    ft_puthash(t_format *format);
void	ft_putprecision(t_format *format);
void	ft_puthex(unsigned long decimal, t_format *format);
void	ft_putdi(int n, t_format *format, size_t len);
void	ft_putsign(int n, t_format *format);
size_t  ft_getnbaselen(unsigned int decimal, size_t base);

void	printer_c(va_list *args, t_format *format) // -
{
	char	c;

	c = (char)va_arg(*args,int);
	format->len = 1;
	if (format->width <= format->len)
	{
		ft_putchar_fd(c, 1);
	}
	else
	{
		if (format->flag_minus)
		{
			ft_putchar_fd(c, 1);
			pads(format->width, format->len, ' ');
		}
		else
		{
			pads(format->width, format->len, ' ');
			ft_putchar_fd(c, 1);
		}
	}
}

void	printer_s(va_list *args, t_format *format) // -.
{
	char	*s;

	s = va_arg(*args, char *);
	format->len = ft_strlen(s);
	if (format->precision < format->len)
		format->len = format->precision;
	if (format->width < format->len)
	{
		ft_putnstr_fd(s, 1, format->len);
	}
	else
	{
		if (format->flag_minus)
		{
			ft_putnstr_fd(s, 1, format->len);
			pads(format->width, format->len, ' ');
		}
		else
		{
			pads(format->width, format->len, ' ');
			ft_putnstr_fd(s, 1, format->len);
		}
	}
}

void	printer_p(va_list *args, t_format *format) // -
{
	void	*p;

	p = va_arg(*args, void *);
	format->len = ft_getbasedigits((unsigned long)p, 16) + 2;
	if (format->width <= format->len)
		ft_putptr_fd(p, 1);
	else
	{
		if (format->flag_minus)
		{
			ft_putptr_fd(p, 1);
			pads(format->width, format->len, ' ');
		}
		else
		{
			pads(format->width, format->len, ' ');
			ft_putptr_fd(p, 1);
		}
	}
}

void	printer_di(va_list *args, t_format *format)
{
	int	di;
	size_t	total_len;

	di = va_arg(*args, int);
	format->len = ft_getnbaselen(di, 10);
	if (format->precision > format->len)
		total_len = format->precision + format->flag_plus + format->flag_space;
	else
		total_len = format->len + format->flag_plus + format->flag_space;
	ft_putdi(di, format, total_len);
}

void	ft_putsign(int n, t_format *format)
{
	if (n > 0)
	{
		if (format->flag_plus)
			ft_putchar_fd(43, 1);
		else if (format->flag_space)
			ft_putchar_fd(32, 1);
	}
}

void	ft_putdi(int n, t_format *format, size_t len)
{
	if (!format->flag_zeros && !format->flag_minus && format->width > len)
		pads(format->width, len, ' ');
	ft_putsign(n, format);
	if (format->flag_zeros && format->width > len)
		pads(format->width, len, '0');
	printf("\nw: - %zu!\n", format->width);
	printf("p: - %zu!\n", format->precision);
	printf("l: - %zu!\n", len);
	ft_putprecision(format);
	ft_putnbr_fd(n, 1);
	if (format->flag_minus && format->width > len)
		pads(format->width, len, ' ');
}

void	printer_u(va_list *args, t_format *format)
{
	unsigned int	u;
	size_t			total_len;

	u = va_arg(*args, unsigned int);
	format->len = ft_getnbaselen(u, 10);
	if (format->precision > format->len)
		total_len = format->precision + format->flag_plus + format->flag_space;
	else
		total_len = format->len + format->flag_plus + format->flag_space;
	if (format->width > total_len)
	{
		if (format->flag_zeros)
		{
			pads(format->width, total_len, '0');
			print_numbers(u, format);
		}
		else if (format->flag_minus)
		{
			print_numbers(u, format);
			pads(format->width, total_len, ' ');
		}
		else
		{
			pads(format->width, total_len, ' ');
			print_numbers(u, format);
		}
	}
	else
		print_numbers(u, format);
}

void	printer_xX(va_list *args, t_format *format)
{
	int		n;
	size_t	total_len;

	n = va_arg(*args, int);
	format->len = ft_getnbaselen(n, 16);
	if (format->precision > format->len)
		total_len = format->precision + (format->flag_hash * 2);
	else
		total_len = format->len + (format->flag_hash * 2);
	//Algoritmo de impresion
	print_hex(n, format, total_len);
}

void	pads(size_t width, size_t len, char flag)
{
	while ((int)width - (int)len > 0)
	{
		ft_putchar_fd(flag, 1);
		width--;
	}
}

void	ft_putnstr_fd(char *s, int fd, size_t n)
{
	size_t	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (i < n && s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	print_numbers(int n, t_format *format)
{
	if (n > 0)
	{
		if (format->flag_plus)
			ft_putchar_fd(43, 1);
		if (format->flag_space)
			ft_putchar_fd(32, 1);
	}
	if (format->precision > format->len)
		pads(format->precision, format->len, '0');
	ft_putnbr_fd(n, 1);
}

void	print_hex(unsigned long decimal, t_format *format, size_t len)
{
	if (!format->flag_zeros && !format->flag_minus && format->width > len)
		pads(format->width, len, ' ');
	ft_puthash(format);
	if (format->flag_zeros && format->width > len)
		pads(format->width, len, '0');
	ft_putprecision(format);
	ft_puthex(decimal, format);
	if (format->flag_minus && format->width > len)
		pads(format->width, len, ' ');
}

void	ft_puthash(t_format *format)
{
	if (format->flag_hash)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(format->specifier, 1);
	}
}

size_t	ft_getnbaselen(unsigned int decimal, size_t base)
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

void	ft_putprecision(t_format *format)
{
	pads(format->precision, format->len, '0');
}

void	ft_puthex(unsigned long decimal, t_format *format)
{
	int	mod;

	mod = decimal % 16;
	if (decimal >= 16)
		ft_puthex(decimal / 16, format);
	if (mod >= 0 && mod <=9)
		ft_putchar_fd((mod) + '0', 1);
	else
	{
		if (format->specifier == 'X')
			ft_putchar_fd(ft_toupper(mod + 39 + '0'),1);
		else
			ft_putchar_fd(mod + 39 + '0',1);
	}
	format->len++;
}

