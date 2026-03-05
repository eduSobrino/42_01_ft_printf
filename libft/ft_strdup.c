/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:04:06 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/05 14:18:48 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	s_len;

	s_len = ft_strlen(s);
	dup = (char *)malloc(s_len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, s_len + 1);
	return (dup);
}
