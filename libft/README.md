*Este proyecto ha sido creado como parte del currículo de 42 por esobrino.*

# Libft

## Descripción
`libft` es una biblioteca de funciones en C que recrea y amplía funcionalidades básicas de la biblioteca estándar de C (`libc`).  
El objetivo principal del proyecto es familiarizarse con la **gestión de memoria dinámica**, la manipulación de **cadenas de caracteres**, punteros, y la implementación de funciones **seguras y norm-compliant**.  

La librería permite a futuros proyectos en C reutilizar funciones comunes, como manipulación de strings, conversión de datos, verificación de caracteres, escritura en file descriptors y más.

---

## Librería Creada
El proyecto genera la librería **`libft.a`** acompañada del header **`libft.h`**, que contiene los prototipos de todas las funciones implementadas.  

### Funciones implementadas

**Manipulación de memoria**
- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`

**Manipulación de cadenas**
- `ft_strlen`, `ft_strdup`, `ft_strchr`, `ft_strrchr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strlcpy`, `ft_strlcat`, `ft_strncmp`, `ft_substr`, `ft_strmapi`, `ft_striteri`

**Conversión**
- `ft_atoi`, `ft_itoa`

**Escritura en file descriptors**
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

**Utilidades**
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`

Todas las funciones cumplen la **norma de 42**: máximo 25 líneas por función, máximo 5 funciones por archivo, no hay asignaciones en condiciones, y manejan `NULL` y fallos de `malloc` donde corresponde.

---

## Instrucciones

1. **Clonar el repositorio:**
```bash
git clone <url-del-repo>

