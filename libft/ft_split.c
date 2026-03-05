/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:41:22 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/03 23:04:53 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t	move_to_last_char(const char *s, size_t *i, char c)
{
	size_t	start;

	start = *i;
	while (s[*i] && s[*i] != c)
		*i = *i + 1;
	return (start);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	j;
	size_t	start;

	if (!s)
		return (NULL);
	matrix = malloc((count_words(s, c) + 1) * 8);
	if (!matrix)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			start = move_to_last_char(s, &i, c);
			matrix[j] = ft_substr(s, start, i - start);
			j++;
		}
		else
			i++;
	}
	matrix[j] = NULL;
	return (matrix);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*tests[] = {
		"holaccquectalccamigos",
		"cholaccquectalccamigos",
		"cccc",
		"hola amigoscc",
		"ccholac amigoscc",
		"",
		" ",
		"c",
		NULL
	};
	char	c = 'c';
	char	**result;
	int		i;
	int		j;

	i = 0;
	while (tests[i])
	{
		printf("TEST %d: \"%s\"\n", i, tests[i]);
		result = ft_split(tests[i], c);
		j = 0;
		while (result && result[j])
		{
			printf("  [%d] \"%s\"\n", j, result[j]);
			free(result[j]);
			j++;
		}
		free(result);
		printf("\n");
		i++;
	}
	return (0);
}
 */
