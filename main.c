/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:51:04 by esobrino          #+#    #+#             */
/*   Updated: 2026/03/14 20:00:00 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

static char	*get_null_str(void)
{
	return ((char *)0);
}

static void	print_case_header(const char *name)
{
	printf("\n==================== %s ====================\n", name);
}

#define RUN_CASE(name, fmt, ...) \
	do { \
		int	ret_lib; \
		int	ret_ft; \
\
		print_case_header(name); \
		printf("printf   -> "); \
		fflush(stdout); \
		ret_lib = printf(fmt, ##__VA_ARGS__); \
		printf("\n"); \
		printf("ft_printf-> "); \
		fflush(stdout); \
		ret_ft = ft_printf(fmt, ##__VA_ARGS__); \
		printf("\n"); \
		printf("return printf=%d | ft_printf=%d\n", ret_lib, ret_ft); \
	} while (0)

int	main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	RUN_CASE("literal", "hola 42");
	RUN_CASE("percent", "[%%]");
	RUN_CASE("char", "[%c][%5c][%-5c]", 'A', 'B', 'C');
	RUN_CASE("char null", "[%c][%5c][%-5c]", '\0', '\0', '\0');
	RUN_CASE("string", "[%s][%10s][%-10s]", "hello", "hello", "hello");
	RUN_CASE("string precision", "[%.3s][%10.3s][%-10.3s]",
		"hello", "hello", "hello");
	RUN_CASE("string null", "[%s][%10s][%-10s]",
		get_null_str(), get_null_str(), get_null_str());
	RUN_CASE("d/i", "[%d][%i][%+5d][% 5d]", -42, 42, 42, 42);
	RUN_CASE("d edge", "[%d][%d]", INT_MIN, INT_MAX);
	RUN_CASE("u", "[%u][%5u][%.0u][%5.0u]", 0u, 42u, 0u, 0u);
	RUN_CASE("x/X", "[%x][%#x][%08x][%X]", 255u, 255u, 255u, 255u);
	RUN_CASE("x zero prec0", "[%.0x][%5.0x][%#5.0x]", 0u, 0u, 0u);
	RUN_CASE("pointer", "[%p][%20p][%-20p]",
		(void *)0x1234abcd, (void *)0x1234abcd, (void *)0x1234abcd);
	RUN_CASE("pointer null", "[%p][%20p][%-20p]",
		(void *)0, (void *)0, (void *)0);
	RUN_CASE("mixed", "abc %d %s %x %% end", 42, "ok", 255);
	printf("\n=======================================================\n");
	return (0);
}
