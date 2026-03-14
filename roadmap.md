# ft_printf Roadmap

## Objetivo
Refactor limpio + comportamiento consistente con `printf` (mandatory), cumpliendo Norminette.

## Estado actual
- [x] Punto de control guardado con commit en rama actual
- [x] `total_len` implementado correctamente
- [ ] Norminette en verde

## Fase 1 - Estabilizacion en `dev`
- [x] 1. Crear commit de checkpoint (estado funcional actual)
- [x] 2. Quitar hardcode en `handler_selector` (usar sentinel/tabla compartida)
- [x] 2.1 Reubicar `specifier_table` fuera de `ft_printf.c` (archivo dedicado de definición)
- [x] 2.2 Definir una única fuente de verdad de specifiers (header/def file) para evitar duplicidad
- [x] 3. Eliminar hardcode de specifiers en parser usando tabla compartida
- [ ] 4. Limpiar estructura/scopes de archivos (prototipos, helpers `static`, includes, nombres)
- [x] 5. Asegurar comportamiento `total_len` en todos los paths (`texto`, handlers y errores)
- [x] 6. Pasar tests de comparación con libc (salida + return) para `cspdiuxX%`
- [ ] 7. Dejar Norminette en verde (sin deuda técnica pendiente)

## Fase 2 - Refactor de texto (`dev`)
- [x] 8. Crear printer común de texto para `%c` y `%s`
- [x] 9. Simplificar handlers `%c`/`%s` para que solo preparen datos
- [x] 10. Verificar no regresiones (width/precision/null string y char nulo)
- [x] 10.1 Revisar `ctx->fmt.len`: texto ya usa `len` explícito por handler/printer

## Fase 3 - Integracion en `dev`
- [ ] 11. Commit de cierre de refactor en `dev`
- [ ] 12. Merge limpio de la rama actual hacia `dev` (si aún no está)

## Fase 4 - Buffer en rama dedicada
- [ ] 13. Crear rama `feature/buffer` desde `dev`
- [ ] 14. Implementar buffer interno (flush por capacidad y al final)
- [ ] 15. Integrar escrituras de todos los printers al buffer
- [ ] 16. Mantener API externa (`ft_printf`) sin cambios
- [ ] 17. Validar equivalencia de salida y retorno vs libc tras buffer
- [ ] 18. Norminette final + commit de cierre de `feature/buffer`

## Extras propuestos
- [ ] E1. Añadir `make test` con matriz mínima automática (salida + retorno)
- [ ] E2. Documento corto de decisiones (`docs/decisions.md`) para justificar diseño de handlers/printers
- [ ] E3. Checklist de release final (build limpio, tests, norm, tamaño funciones)

## Regla de trabajo
- Un commit por bloque lógico cerrado y verificable.
- No avanzar de fase sin marcar todos los checks de la fase anterior.
