/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:28:49 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 19:59:31 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pf_putchar(t_context *ctx, char c)
{
	ssize_t	w;

	w = write(1, &c, 1);
	if (w > 0)
		ctx->total_len += w;
}

void	pf_putnchar(t_context *ctx, char c, size_t n)
{
	ssize_t	w;

	while (n > 0)
	{
		w = write(1, &c, 1);
		if (w < 1)
			return ;
		ctx->total_len += w;
		n--;
	}
}

void	pf_putstrn(t_context *ctx, const char *s, size_t n)
{
	ssize_t	w;
	size_t	i;

	i = 0;
	while (s && i < n)
	{
		w = write(1, s + i, 1);
		if (w < 1)
			return ;
		ctx->total_len += w;
		i++;
	}
}
