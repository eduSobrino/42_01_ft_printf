# Guia general de valores limite en C

## Objetivo
Este documento resume los valores limite importantes por tipo de dato en C, los riesgos asociados y cuando conviene aplicar chequeos de limites.

No esta centrado en un proyecto concreto: es una referencia general para diseno, implementacion y tests.

## 1. Principio base
- No asumas tamanos fijos de tipos basicos (`int`, `long`, `char`).
- Usa macros de `<limits.h>` y `<float.h>` para conocer limites reales en tu plataforma.
- Siempre que un valor venga de fuera (usuario, red, fichero, argv, DB), valida rango antes de usarlo.

## 2. Enteros: limites y uso

### 2.1 Tipos enteros clasicos
Referencias: `<limits.h>`

- `signed char`: `SCHAR_MIN` .. `SCHAR_MAX`
- `unsigned char`: `0` .. `UCHAR_MAX`
- `short`: `SHRT_MIN` .. `SHRT_MAX`
- `unsigned short`: `0` .. `USHRT_MAX`
- `int`: `INT_MIN` .. `INT_MAX`
- `unsigned int`: `0` .. `UINT_MAX`
- `long`: `LONG_MIN` .. `LONG_MAX`
- `unsigned long`: `0` .. `ULONG_MAX`
- `long long`: `LLONG_MIN` .. `LLONG_MAX`
- `unsigned long long`: `0` .. `ULLONG_MAX`

Cuanto aplicarlo:
- Antes de sumas/restas/multiplicaciones con riesgo de overflow.
- Antes de cast de tipo grande a tipo pequeno (narrowing).
- Al parsear texto a numero (`strtol`, `strtoll`, etc.).

### 2.2 Tipos de ancho fijo
Referencias: `<stdint.h>`

- `int8_t`, `int16_t`, `int32_t`, `int64_t`
- `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t`

Cuanto aplicarlo:
- Protocolos binarios.
- Formatos de fichero.
- Networking.
- Criptografia y serializacion.

Ventaja:
- Rango estable entre plataformas.

### 2.3 `size_t`, `ptrdiff_t`, `ssize_t`
- `size_t`: tamano/capacidad de memoria (siempre sin signo).
- `ptrdiff_t`: diferencia entre punteros (con signo).
- `ssize_t` (POSIX): resultado de lecturas/escrituras que puede ser negativo por error.

Cuanto aplicarlo:
- Indices y longitudes de buffers.
- `malloc`, `calloc`, `memcpy`, `read`, `write`.

Riesgo tipico:
- Mezclar `int` con `size_t` y romper comparaciones por conversion implicita.

## 3. Flotantes: limites y precision
Referencias: `<float.h>`

- `float`: `FLT_MIN`, `FLT_MAX`, `FLT_EPSILON`
- `double`: `DBL_MIN`, `DBL_MAX`, `DBL_EPSILON`
- `long double`: `LDBL_MIN`, `LDBL_MAX`, `LDBL_EPSILON`

Importante:
- `*_MIN` es el minimo positivo normalizado, no el mas negativo.
- Existen `+inf`, `-inf`, `NaN`.

Cuanto aplicarlo:
- Calculo numerico.
- Comparaciones de igualdad (usar tolerancia).
- Lectura de datos de sensores y APIs.

Regla practica:
- Evita `a == b` en coma flotante; usa margen (`fabs(a - b) < eps`).

## 4. `char` y texto

### 4.1 `char` firmado o no
- `char` puede ser signed o unsigned segun compilador/arquitectura.
- Si necesitas semantica exacta, usa `signed char` o `unsigned char`.

Cuanto aplicarlo:
- Procesado de bytes crudos.
- Tablas de lookup indexadas por byte.

### 4.2 Strings C
- Deben terminar en `'\0'`.
- Riesgos: off-by-one, falta de terminador, sobrelectura/sobrescritura.

Cuanto aplicarlo:
- `strcpy/strcat/sprintf` (alto riesgo).
- Cualquier copia o formateo en buffers estaticos.

## 5. Punteros y nulos
- `NULL` es valor invalido para desreferenciar.
- Nunca asumas que un puntero externo es valido.

Cuanto aplicarlo:
- Entrada de funciones publicas.
- Estructuras parcialmente inicializadas.
- Error paths y cleanup.

## 6. Operaciones peligrosas (UB/errores)

### 6.1 Overflow de enteros con signo
- Overflow en signed integer es comportamiento indefinido (UB).

### 6.2 Overflow de enteros sin signo
- En unsigned hay wrap modular (definido), pero puede ser bug logico.

### 6.3 Casos clasicos
- `abs(INT_MIN)` desborda en `int`.
- `-INT_MIN` en el mismo tipo desborda.
- Shift con cantidad negativa o `>=` ancho del tipo: UB.
- Division/modulo por cero: UB.
- Mismatch de tipos en `va_arg`: UB.

Cuanto aplicarlo:
- Aritmetica de indices.
- Formateo numerico.
- Varargs y APIs tipo `printf`.

## 7. Patrones de chequeo recomendados

### 7.1 Suma segura
```c
if (a > INT_MAX - b) { /* overflow */ }
```

### 7.2 Multiplicacion segura para reserva
```c
if (n != 0 && size > SIZE_MAX / n) { /* overflow */ }
```

### 7.3 Parseo robusto con `strtol`
```c
errno = 0;
long v = strtol(s, &end, 10);
if (errno == ERANGE) { /* fuera de rango */ }
if (end == s || *end != '\0') { /* entrada invalida */ }
if (v < INT_MIN || v > INT_MAX) { /* no cabe en int */ }
```

## 8. Cuando conviene cada tipo (regla practica)
- `int`: logica general y contadores pequenos/medios.
- `size_t`: tamano de memoria y longitudes.
- `uint*_t`/`int*_t`: datos con formato binario fijo.
- `long long`/`int64_t`: acumuladores grandes, timestamps amplios.
- `double`: calculo real general.
- `float`: cuando memoria/ancho de banda mandan.

## 9. Estrategia de tests de borde
Para cada funcion critica, prueba:
- Minimo, maximo y cero.
- Justo dentro y justo fuera de rango.
- Valores negativos donde aplique.
- Casos vacios (`NULL`, string vacia, longitud 0).
- Datos grandes para detectar overflow en calculos de tamano.

Ejemplo de set minimo para `int`:
- `INT_MIN`, `INT_MIN + 1`, `-1`, `0`, `1`, `INT_MAX - 1`, `INT_MAX`

## 10. Checklist rapido antes de cerrar una funcion
- El tipo elegido expresa bien el dominio del dato.
- Todas las conversiones de tipo son seguras.
- No hay riesgo de overflow en calculos intermedios.
- Se valida entrada externa antes de usarla.
- Se cubren limites en tests unitarios.
- El comportamiento ante error esta definido (return, errno, mensaje, etc.).

## 11. Regla final de diseno
Si dudas entre dos tipos, elige el que haga imposible una clase de bug.

Ejemplo:
- Longitudes y capacidades: `size_t`.
- Datos de protocolo: `uint32_t` en vez de `unsigned int`.
- Diferencias de punteros: `ptrdiff_t`.

La eleccion de tipo es una decision de seguridad y mantenibilidad, no solo de sintaxis.
