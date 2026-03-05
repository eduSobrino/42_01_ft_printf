/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:51:11 by esobrino          #+#    #+#             */
/*   Updated: 2026/01/27 20:04:05 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lst_size;
	t_list	*curr;

	lst_size = 0;
	curr = lst;
	while (curr != NULL)
	{
		lst_size++;
		curr = curr->next;
	}
	return (lst_size);
}
