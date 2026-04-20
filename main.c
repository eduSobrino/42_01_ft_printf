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

static const char	*get_long_str(void)
{
	return ("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
		"eiusmod tempor incididunt ut labore et dolore magna aliqua.");
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

#define RUN_CASE_DYNAMIC(name, fmt_var, ...) \
	do { \
		int			ret_lib; \
		int			ret_ft; \
		const char	*dyn_fmt; \
\
		dyn_fmt = (fmt_var); \
		print_case_header(name); \
		printf("printf   -> "); \
		fflush(stdout); \
		ret_lib = printf(dyn_fmt, ##__VA_ARGS__); \
		printf("\n"); \
		printf("ft_printf-> "); \
		fflush(stdout); \
		ret_ft = ft_printf(dyn_fmt, ##__VA_ARGS__); \
		printf("\n"); \
		printf("return printf=%d | ft_printf=%d\n", ret_lib, ret_ft); \
	} while (0)

/* -------------------------------------------------------------------------- */
/* Basic literals, percent and char                                            */
/* -------------------------------------------------------------------------- */
static void	run_basic_cases(void)
{
	RUN_CASE("literal", "hola 42");
	RUN_CASE("percent", "[%%]");
	RUN_CASE("char", "[%c][%5c][%-5c]", 'A', 'B', 'C');
	RUN_CASE("char null", "[%c][%5c][%-5c]", '\0', '\0', '\0');
}

/* -------------------------------------------------------------------------- */
/* Strings: basic width, precision, null handling and truncation               */
/* -------------------------------------------------------------------------- */
static void	run_string_cases(void)
{
	RUN_CASE("string", "[%s][%10s][%-10s]", "hello", "hello", "hello");
	RUN_CASE("string precision", "[%.3s][%10.3s][%-10.3s]",
		"hello", "hello", "hello");
	RUN_CASE("string precision zero", "[%.0s][%5.0s][%-5.0s]",
		"hello", "hello", "hello");
	RUN_CASE("string null", "[%s][%10s][%-10s]",
		get_null_str(), get_null_str(), get_null_str());
	RUN_CASE("string long", "[%.20s][%40.20s][%-40.20s]",
		get_long_str(), get_long_str(), get_long_str());
}

/* -------------------------------------------------------------------------- */
/* Signed integers: width, sign, zero padding, precision and priority rules    */
/* -------------------------------------------------------------------------- */
static void	run_signed_cases(void)
{
	const char	*d_prio_fmt;

	d_prio_fmt = "[%-05d][%+ d][%08.5d]";
	RUN_CASE("d/i", "[%d][%i][%+5d][% 5d]", -42, 42, 42, 42);
	RUN_CASE("d edge", "[%d][%d]", INT_MIN, INT_MAX);
	RUN_CASE("d zero padding", "[%05d][%+05d][% 05d]", 42, 42, 42);
	RUN_CASE("d negative zero padding", "[%05d][%010d]", -42, INT_MIN);
	RUN_CASE("d precision", "[%.5d][%8.5d][%-8.5d]", 42, 42, 42);
	RUN_CASE("d zero precision", "[%.0d][%5.0d][%+.0d][% .0d]",
		0, 0, 0, 0);
	RUN_CASE_DYNAMIC("d priority rules", d_prio_fmt, 42, 42, 42);
}

/* -------------------------------------------------------------------------- */
/* Unsigned and hex: width, precision, hash flag and priority rules            */
/* -------------------------------------------------------------------------- */
static void	run_unsigned_cases(void)
{
	const char	*x_prio_fmt;

	x_prio_fmt = "[%-#08x][%#08.5x]";
	RUN_CASE("u", "[%u][%5u][%.0u][%5.0u]", 0u, 42u, 0u, 0u);
	RUN_CASE("u precision", "[%.5u][%8.5u][%-8.5u]", 42u, 42u, 42u);
	RUN_CASE("x/X", "[%x][%#x][%08x][%X]", 255u, 255u, 255u, 255u);
	RUN_CASE("x zero prec0", "[%.0x][%5.0x][%#5.0x]", 0u, 0u, 0u);
	RUN_CASE("x precision", "[%.5x][%#10.5x][%-#10.5x]",
		255u, 255u, 255u);
	RUN_CASE("x hash zero", "[%#x][%#.0x][%#8x]", 0u, 0u, 0u);
	RUN_CASE("X hash", "[%#X][%#10X][%-#10X]", 48879u, 48879u, 48879u);
	RUN_CASE_DYNAMIC("x priority rules", x_prio_fmt, 255u, 255u);
}

/* -------------------------------------------------------------------------- */
/* Pointers: regular values, null pointers and wide alignment checks           */
/* -------------------------------------------------------------------------- */
static void	run_pointer_cases(void)
{
	RUN_CASE("pointer", "[%p][%20p][%-20p]",
		(void *)0x1234abcd, (void *)0x1234abcd, (void *)0x1234abcd);
	RUN_CASE("pointer null", "[%p][%20p][%-20p]",
		(void *)0, (void *)0, (void *)0);
	RUN_CASE("pointer width", "[%30p][%-30p]", (void *)(uintptr_t)UINTPTR_MAX,
		(void *)(uintptr_t)UINTPTR_MAX);
}

/* -------------------------------------------------------------------------- */
/* Mixed sequences: integration-style cases combining several specifiers       */
/* -------------------------------------------------------------------------- */
static void	run_mixed_cases(void)
{
	RUN_CASE("mixed", "abc %d %s %x %% end", 42, "ok", 255);
	RUN_CASE("mixed dense", "[%c|%s|%p|%d|%i|%u|%x|%X|%%]",
		'Z', "mix", (void *)0x42, -123, 456, 789u, 48879u, 48879u);
	RUN_CASE("sequence", "%d %d %d %x %x %s %c %%",
		1, 2, 3, 4u, 5u, "done", '!');
}

int	main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);

	/* Block 1: literals, percent and chars */
	run_basic_cases();
	/* Block 2: strings */
	run_string_cases();
	/* Block 3: signed integers */
	run_signed_cases();
	/* Block 4: unsigned and hex */
	run_unsigned_cases();
	/* Block 5: pointers */
	run_pointer_cases();
	/* Block 6: mixed integration cases */
	run_mixed_cases();
	printf("\n=======================================================\n");
	return (0);
}
