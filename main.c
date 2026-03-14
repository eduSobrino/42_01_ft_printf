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
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define CAPTURE_TO(path, ret_var, call_expr) \
	do { \
		int	saved_fd; \
		int	out_fd; \
\
		saved_fd = dup(STDOUT_FILENO); \
		out_fd = open((path), O_CREAT | O_WRONLY | O_TRUNC, 0644); \
		if (saved_fd < 0 || out_fd < 0) \
		{ \
			perror("capture"); \
			exit(EXIT_FAILURE); \
		} \
		fflush(stdout); \
		if (dup2(out_fd, STDOUT_FILENO) < 0) \
		{ \
			perror("dup2"); \
			exit(EXIT_FAILURE); \
		} \
		close(out_fd); \
		(ret_var) = (call_expr); \
		fflush(stdout); \
		if (dup2(saved_fd, STDOUT_FILENO) < 0) \
		{ \
			perror("dup2"); \
			exit(EXIT_FAILURE); \
		} \
		close(saved_fd); \
	} while (0)

#define RUN_TEST(label, fmt, ...) \
	do { \
		int		ret_ft; \
		int		ret_lib; \
		char	ft_path[128]; \
		char	lib_path[128]; \
\
		snprintf(ft_path, sizeof(ft_path), "/tmp/ft_%d_%zu.bin", getpid(), case_id); \
		snprintf(lib_path, sizeof(lib_path), "/tmp/lib_%d_%zu.bin", getpid(), case_id); \
		CAPTURE_TO(ft_path, ret_ft, ft_printf(fmt, ##__VA_ARGS__)); \
		CAPTURE_TO(lib_path, ret_lib, printf(fmt, ##__VA_ARGS__)); \
		total_cases++; \
		ok_cases += report_case(label, ft_path, lib_path, ret_ft, ret_lib); \
		unlink(ft_path); \
		unlink(lib_path); \
		case_id++; \
	} while (0)

static unsigned char	*load_file(const char *path, size_t *len)
{
	unsigned char	*buf;
	struct stat		st;
	FILE			*f;
	size_t			read_n;

	if (stat(path, &st) != 0)
		return (NULL);
	*len = (size_t)st.st_size;
	buf = (unsigned char *)malloc(*len + 1);
	if (!buf)
		return (NULL);
	f = fopen(path, "rb");
	if (!f)
	{
		free(buf);
		return (NULL);
	}
	read_n = fread(buf, 1, *len, f);
	fclose(f);
	if (read_n != *len)
	{
		free(buf);
		return (NULL);
	}
	buf[*len] = '\0';
	return (buf);
}

static void	print_visible(const unsigned char *buf, size_t len)
{
	size_t					i;
	unsigned char			c;
	const size_t			max = 220;

	i = 0;
	while (i < len && i < max)
	{
		c = buf[i];
		if (c == '\n')
			printf("\\n");
		else if (c == '\t')
			printf("\\t");
		else if (c == '\0')
			printf("\\0");
		else if (isprint(c))
			printf("%c", c);
		else
			printf("\\x%02X", c);
		i++;
	}
	if (len > max)
		printf("...");
}

static int	report_case(const char *label, const char *ft_path,
			const char *lib_path, int ret_ft, int ret_lib)
{
	unsigned char	*ft_out;
	unsigned char	*lib_out;
	size_t			ft_len;
	size_t			lib_len;
	int				same;

	ft_out = load_file(ft_path, &ft_len);
	lib_out = load_file(lib_path, &lib_len);
	if (!ft_out || !lib_out)
	{
		free(ft_out);
		free(lib_out);
		printf("[KO] %s -> file read error\n", label);
		return (0);
	}
	same = (ret_ft == ret_lib && ft_len == lib_len
			&& memcmp(ft_out, lib_out, ft_len) == 0);
	if (same)
		printf("[OK] %s\n", label);
	else
	{
		printf("[KO] %s\n", label);
		printf("  ret: ft=%d libc=%d\n", ret_ft, ret_lib);
		printf("  len: ft=%zu libc=%zu\n", ft_len, lib_len);
		printf("  ft : ");
		print_visible(ft_out, ft_len);
		printf("\n  lc : ");
		print_visible(lib_out, lib_len);
		printf("\n");
	}
	free(ft_out);
	free(lib_out);
	return (same);
}

static char	*get_null_str(void)
{
	return ((char *)0);
}

int	main(void)
{
	size_t	case_id;
	size_t	total_cases;
	size_t	ok_cases;

	case_id = 0;
	total_cases = 0;
	ok_cases = 0;
	RUN_TEST("literal", "hola 42\\n");
	RUN_TEST("percent", "[%%]\\n");
	RUN_TEST("char basic", "[%c]\\n", 'A');
	RUN_TEST("char null", "[%c]\\n", '\0');
	RUN_TEST("char width left", "[%-5c]\\n", 'Z');
	RUN_TEST("char width right", "[%5c]\\n", 'Z');
	RUN_TEST("str basic", "[%s]\\n", "hello");
	RUN_TEST("str null", "[%s]\\n", get_null_str());
	RUN_TEST("str precision", "[%.3s]\\n", "hello");
	RUN_TEST("str width+prec", "[%10.3s]\\n", "hello");
	RUN_TEST("d/i", "[%d][%i][%+5d][% 5d]\\n", -42, 42, 42, 42);
	RUN_TEST("d edge", "[%d][%d]\\n", INT_MIN, INT_MAX);
	RUN_TEST("u", "[%u][%5u][%.0u][%5.0u]\\n", 0u, 42u, 0u, 0u);
	RUN_TEST("x/X", "[%x][%#x][%08x][%X]\\n", 255u, 255u, 255u, 255u);
	RUN_TEST("x zero prec0", "[%.0x][%5.0x][%#5.0x]\\n", 0u, 0u, 0u);
	RUN_TEST("pointer", "[%p][%20p][%-20p]\\n", (void *)0x1234abcd,
		(void *)0x1234abcd, (void *)0x1234abcd);
	RUN_TEST("pointer null", "[%p][%20p][%-20p]\\n", (void *)0,
		(void *)0, (void *)0);
	RUN_TEST("mixed", "abc %d %s %x %% end\\n", 42, "ok", 255);
	printf("\nSummary: %zu/%zu OK\n", ok_cases, total_cases);
	if (ok_cases != total_cases)
		return (1);
	return (0);
}
