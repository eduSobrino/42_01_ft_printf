# ft_printf

Implementación de `ft_printf` para el currículo de 42.

## Objetivo
Reproducir el comportamiento de `printf` para las conversiones obligatorias:

- `%c`
- `%s`
- `%p`
- `%d`
- `%i`
- `%u`
- `%x`
- `%X`
- `%%`

Prototipo:

```c
int	ft_printf(const char *format, ...);
```

## Compilación y uso

Compilar librería:

```bash
make
```

Limpiar objetos:

```bash
make clean
```

Limpiar todo:

```bash
make fclean
```

Recompilar:

```bash
make re
```

Test comparativo (`printf` vs `ft_printf`) usando `main.c`:

```bash
make test
```

Chequeo de norma:

```bash
norminette src inc libftprintf.h
```

## Arquitectura

El proyecto está dividido por capas:

- `parser/`
  - Parseo de flags, width, precision y specifier.
  - `parse_number_sat.c` evita overflow de parseo saturando a `INT_MAX`.
- `dispatcher/`
  - Tabla única de specifiers (`get_spec_table.c`) con:
    - specifier
    - handler
    - flags permitidas
  - Aplicación de reglas de prioridad de flags.
- `handler/`
  - Extraen argumentos (`va_arg`) y preparan la vista del dato.
- `utils/`
  - `text_printer.c` y `number_printer.c` construyen salida formateada.
  - `buffer_manager.c` gestiona buffer de salida y flush a `write`.

## Reglas de diseño aplicadas

- Fuente única de verdad para specifiers: `spec_table`.
- Separación de responsabilidades:
  - parser parsea
  - dispatcher selecciona y normaliza
  - handlers preparan datos
  - printers renderizan
  - buffer manager escribe
- Encapsulación de tipos internos en `inc/`:
  - `spec_table.h`
  - `num_fmt.h`
  - `number_printer_lengths.h`
  - `parse_number_sat.h`
- Manejo de errores de runtime:
  - error de `write` => `ft_printf` retorna `-1`
  - control de overflow de retorno (`INT_MAX`)
  - flush final al terminar el procesamiento del formato

## Flags soportadas

Flags parseadas: `-0# +` y `.` (precisión).  
La validez final por conversión se controla en la tabla de specifiers + reglas de prioridad.

## Specifier y flags permitidas

| Specifier | Flags permitidas |
| --- | --- |
| `%c` | `-` |
| `%s` | `-` `.` |
| `%p` | `-` |
| `%d` `%i` | `-` `0` `.` `+` ` ` |
| `%u` | `-` `0` `.` |
| `%x` `%X` | `-` `0` `.` `#` |
| `%%` | ninguna |

Reglas de prioridad globales:

- `-` desactiva `0`
- `+` desactiva espacio (` `)
- `.` desactiva `0` en `%d` `%i` `%u` `%x` `%X`

## Estructura de carpetas

```text
inc/
src/
  parser/
  dispatcher/
  handler/
  utils/
libftprintf.h
Makefile
```

## Notas

- `make test` es un target auxiliar para desarrollo y no forma parte del flujo obligatorio de `all`.
- La salida se bufferiza para reducir llamadas a `write`.

## Limitaciones conocidas

- No se implementan length modifiers (`hh`, `h`, `l`, `ll`, etc.).
- No se implementan conversiones de coma flotante (`%f`, `%e`, `%g`, ...).
- No se implementan `*` en width/precision.
- Comportamientos fuera de especificación (format inválido o tipos variádicos incorrectos) se consideran fuera de alcance del proyecto.
- El retorno está limitado por `INT_MAX` (si hay overflow o error de escritura, retorna `-1`).

## Changelog breve

- `v1` implementación funcional base de `cspdiuxX%`.
- `v2` refactor por capas (`parser`/`dispatcher`/`handler`/`utils`) y tabla única de specifiers.
- `v3` normalización de flags por máscara y reglas de prioridad.
- `v4` capa de impresión común (`text_printer` y `number_printer`) con `total_len` consistente.
- `v5` buffering de salida en `buffer_manager` + manejo robusto de `write`/overflow.
- `v6` encapsulación de tipos internos en `inc/` (`spec_table`, `num_fmt`, `number_printer_lengths`, `parse_number_sat`).
