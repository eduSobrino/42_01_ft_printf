# ft_printf()

*Este proyecto ha sido creado como parte del currículo de 42 por esobrino.*

## Descrpición
Escribe una librería que contenga la función ft_printf(), que imite el printf() original.
prototipo:

`int		ft_printf(char const *, ...);`

Introducción a las funciones variádicas.

#### Archivos a entregar 
Makefile, *.h, */*.h, *.c, */*.c

#### Makefile
NAME, all, clean, fclean, re

#### Funciones autorizadas
libft
malloc, free, write --> stdlib.h y unsitd.h
va_start, va_arg, va_copy, va_end --> stdargs.h 

## Instrucciones

Se deben incluir las conversiones cspdiuxX%:

%specifier | Definition | ----------------------------------------------------> Output example

c: Characer ------------------------------------------------------------------> a

s: String of cahracters ------------------------------------------------------> sample

p: Pointer of address --------------------------------------------------------> b8000000

d: Signed decimal integer ----------------------------------------------------> 392

i: Signed decimal integer ----------------------------------------------------> 392

u: Unsigned decimal integer --------------------------------------------------> 7235

x: Hexadecimal floating point, lowercase -------------------------------------> 7fa

X: Hexadecimal floating point, uppercase -------------------------------------> 7FA

%: A % followed by another % character will write a single %to the stream ----> %

## Recursos

Documentación de c standard
https://cplusplus.com/reference/cstdio/printf/

Calculadora de conversión de base para desarrollar y comparar ft_dectobase.c
https://www.rapidtables.com/convert/number/index.html
