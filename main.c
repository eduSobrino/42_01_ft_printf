/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrino <esobrino@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:51:04 by esobrino          #+#    #+#             */
/*   Updated: 2026/02/27 01:03:43 by esobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	void	*ptr = "Hello 42";
	char	*str = "Hello 42";

	printf("%%c - Char: %-5c HOLA\n", 'b'); // -
	ft_printf("%%c - Char: %-5c HOLA\n\n", 'b'); // -
	printf("%%s - String: %15.15s !\n", str); // -.
	ft_printf("%%s - String: %15.15s !\n\n", str, str); // -.
	printf("%%p - Pointer: %20p!\n", ptr); // -
	ft_printf("%%p - Pointer: %20p!\n\n", ptr); // -
	printf("%%d - Decimal: %010d\n", -4225); // -0. +
	ft_printf("%%d - Decimal: %010d\n\n", -4225); // -0. +
	printf("%%u - Unsigned: %-10.4u HOLA\n", -6); // -0.
	ft_printf("%%u - Unsigned: %-10.4u HOLA\n\n", -6); // -0.
	printf("%%x - hex lower: %#10.2x\n", -1252); // -0#.
	ft_printf("%%x - hex lower: %#10.2x\n\n", -1252); // -0#.
	printf("%%X - HEX UPPER: %#10.2X !\n", -1252); // -0#.
	ft_printf("%%X - HEX UPPER: %#10.2X !\n\n", -1252); // -0#.
	printf("%%%% - %%: %%\n"); 
	return (0);
}
/*
 * Implementar toupper
 * Modificar el return de ft_putptr_fd a void * - probar con un simple cast
 * Modificar funciones de hexadecimales
 * Modular funciones
 * automatizar parámetros hardcodeados
 * Generar error si el numero de argumentos es superior al numero de especificadores
 * Control de errores - por ejemplo s! en putstr
 * Bonus - control de flags incompatibles
 * - * con width y precision
 * - prefijos en los especificadores como l, ll... etc
 */ 
