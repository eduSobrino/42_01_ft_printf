/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectobase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:36:00 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/24 21:25:51 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_getbasedigits(unsigned long dec, size_t base);
void	ft_dectobase_str(char *str, unsigned long dec, size_t n_base);

char	*ft_dectobase(unsigned long dec, size_t base)
{
	char	*result;
	size_t	n_digits;
	
	n_digits = ft_getbasedigits(dec, base);
	result = ft_calloc(n_digits + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_dectobase_str(result + n_digits - 1, dec, base);
	return (result);
}

size_t	ft_getbasedigits(unsigned long dec, size_t base)
{
	size_t	n_digits;

	n_digits = 1;
	while(dec >= base)
	{
		n_digits++;
		dec = dec / base;
	}
	return(n_digits);
}

void	ft_dectobase_str(char *str, unsigned long dec, size_t n_base)
{
	char	bases[17] = "0123456789abcdef";

	if (dec >= n_base)
		ft_dectobase_str(str - 1, dec / n_base, n_base);
	str[0] = bases[dec % n_base];
}
