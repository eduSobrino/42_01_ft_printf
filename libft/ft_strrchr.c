/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 23:15:54 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/03 15:32:37 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;

	len = ft_strlen(s);
	while (1)
	{
		if ((unsigned char)s[len] == (unsigned char)c)
			return ((char *)s + len);
		if (len == 0)
			break ;
		len--;
	}
	return (NULL);
}
