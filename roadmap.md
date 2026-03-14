# ft_printf Roadmap

## Objetivo
Refactor limpio + comportamiento consistente con `printf` (mandatory), cumpliendo Norminette.

## Estado actual
- [ ] Punto de control guardado con commit en rama actual
- [ ] `total_len` implementado correctamente
- [ ] Norminette en verde

## Fase 1 - Estabilizacion en `dev`
- [ ] 1. Crear commit de checkpoint (estado funcional actual)
- [ ] 2. Quitar hardcode en `handler_selector` (usar longitud de tabla)
- [ ] 3. Declarar `SPECIFIERS` en header con `#define` compatible con Norminette
- [ ] 4. Limpiar estructura/scopes de archivos (prototipos, helpers `static`, includes, nombres)
- [ ] 5. Asegurar comportamiento `total_len` en todos los paths (`texto`, handlers y errores)
- [ ] 6. Pasar tests de comparación con libc (salida + return) para `cspdiuxX%`
- [ ] 7. Dejar Norminette en verde (sin deuda técnica pendiente)

## Fase 2 - Refactor de texto (`dev`)
- [ ] 8. Crear printer común de texto para `%c` y `%s`
- [ ] 9. Simplificar handlers `%c`/`%s` para que solo preparen datos
- [ ] 10. Verificar no regresiones (width/precision/null string y char nulo)
- [ ] 10.1 Revisar `ctx->fmt.len`: puede desaparecer en texto o redefinirse con nuevo contrato

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
