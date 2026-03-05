/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:29:13 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/24 19:03:00 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putptr_fd(void *ptr, int fd)
{	
	char	*hex;

	hex = ft_dectobase((unsigned long)ptr, 16);
	if (!hex)
		return ;
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(hex, fd);
	free(hex);
}
