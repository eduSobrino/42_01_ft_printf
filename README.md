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

## Hoja de Ruta Ninja (Próximos Pasos)

Para elevar la calidad del código, se están implementando los siguientes conceptos de ingeniería de software:

1.  **[ ] Fase 1: Arquitectura de Configuración (X-Macros)**
    *   Centralizar specifiers y flags en `ft_printf_config.h`.
    *   Usar macros para autogenerar la tabla de handlers y los strings de búsqueda.
2.  **[ ] Fase 2: Optimización de Datos (Bitmasks)**
    *   Sustituir booleanos en `t_format` por una bitmask de 8 bits.
    *   Implementar validación de flags con operadores bitwise (`&`, `|`, `~`).
3.  **[ ] Fase 3: Acceso Directo (Lookup Table ASCII)**
    *   Convertir el selector en una tabla indexada $O(1)$ usando el valor ASCII de los caracteres.
4.  **[ ] Fase 4: Contador y Encapsulación (Contexto)**
    *   Crear una estructura `t_printf` que agrupe `va_list`, `t_format` y el acumulador de bytes.
    *   Implementar el retorno correcto del número de caracteres impresos.
5.  **[ ] Fase 5 (Bonus): Buffering de Impresión**
    *   Implementar un buffer interno para minimizar las llamadas a `write(1, ...)`.
