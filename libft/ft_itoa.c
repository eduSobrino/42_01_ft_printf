/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:13:02 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/05 14:13:09 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	size_t	i;
	int		flag;
	long	num;

	flag = 1;
	if (n == 0)
		return (1);
	num = (long)n;
	if (num < 0)
	{
		flag = -1;
		num = -num;
	}
	i = 0;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	if (flag < 0)
		return (i + 1);
	else
		return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	long	num;

	len = ft_num_len(n);
	str = (void *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[len] = '\0';
	num = (long)n;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	i = len - 1;
	while (i >= 0 && !(str[0] == '-' && i == 0))
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (str);
}
/* #include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	char	*res;

	res = ft_itoa(0);
	printf("0 → %s\n", res);
	free(res);
	res = ft_itoa(5);
	printf("5 → %s\n", res);
	free(res);
	res = ft_itoa(42);
	printf("42 → %s\n", res);
	free(res);
	res = ft_itoa(-42);
	printf("-42 → %s\n", res);
	free(res);
	res = ft_itoa(123456);
	printf("123456 → %s\n", res);
	free(res);
	res = ft_itoa(-98765);
	printf("-98765 → %s\n", res); 
	res = ft_itoa(-2147483648);
	printf("-2147483648 → %s\n", res);
	res = ft_itoa(2147483648);
	printf("2147483647 → %s\n", res);
	free(res);
	return (0);
} */
