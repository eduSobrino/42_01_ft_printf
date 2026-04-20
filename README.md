*This project has been created as part of the 42 curriculum by esobrino.*

# ft_printf

## Description
`ft_printf` is a custom implementation of the standard C `printf` function for the mandatory scope of the 42 project.

The goal is to reproduce the observable behavior of `printf` for a restricted and well-defined subset of conversions while building the feature from first principles: variadic argument handling, format parsing, dispatching, numeric rendering, width and precision handling, and buffered output.

Supported conversions:

- `%c`
- `%s`
- `%p`
- `%d`
- `%i`
- `%u`
- `%x`
- `%X`
- `%%`

Public prototype:

```c
int	ft_printf(const char *format, ...);
```

At a high level, the project parses each conversion specification, normalizes the active flags according to the target specifier, extracts the next variadic argument, formats it, and writes the final output through an internal fixed-size buffer.

## Features
- Mandatory conversion set fully implemented: `cspdiuxX%`.
- Support for width and precision where applicable.
- Support for the parsed flags `-`, `0`, `#`, space, `+`, and `.` with per-specifier validation.
- Internal dispatch table as the single source of truth for supported specifiers and allowed flags.
- Buffered output to reduce the number of `write()` system calls.
- Runtime error handling for `write()` failures and return value overflow.

## Instructions
### Build
Compile the library:

```bash
make
```

Rebuild from scratch:

```bash
make re
```

Remove local objects and dependency files:

```bash
make clean
```

Remove local objects, dependency files, and generated libraries:

```bash
make fclean
```

### Use in another program
After `make`, the repository root contains `libftprintf.a`.

Typical usage:

```bash
cc -Wall -Wextra -Werror your_file.c -L. -lftprintf -o your_program
```

Example:

```c
#include "libftprintf.h"

int	main(void)
{
	ft_printf("Hello %s, value=%d\n", "42", 42);
	return (0);
}
```

### Norm check

```bash
norminette src inc libftprintf.h
```

### Notes about the Makefile
The project Makefile intentionally keeps the local comparison test block commented out.

This design serves two goals:

- The deliverable version of the project stays clean for 42 submission.
- The local developer workflow can still be restored quickly when needed.

The commented block at the end of `Makefile` shows how to re-enable a local `make test` target that compiles `main.c` and compares `printf` against `ft_printf`. This helper is meant for personal development only and should not be part of the final submission if it includes `stdio.h` and calls to the original libc `printf`.

## Supported Flags and Rules
Parsed flags:

- `-`
- `0`
- `#`
- space
- `+`
- precision `.` 

Supported flag matrix:

| Specifier | Allowed flags |
| --- | --- |
| `%c` | `-` |
| `%s` | `-` `.` |
| `%p` | `-` |
| `%d` `%i` | `-` `0` `.` `+` space |
| `%u` | `-` `0` `.` |
| `%x` `%X` | `-` `0` `.` `#` |
| `%%` | none |

Priority rules applied globally:

- `-` disables `0`
- `+` disables space
- precision disables `0` for `%d`, `%i`, `%u`, `%x`, and `%X`

## Algorithm and Data Structure Choices
### Why this architecture
The project is structured as a small formatting pipeline instead of one monolithic function. This was a deliberate choice to keep the code maintainable, norm-compliant, and easy to reason about when handling multiple conversions with different rules.

The pipeline is split into four layers:

- `parser/`: reads flags, width, precision, and the specifier.
- `dispatcher/`: validates the specifier, masks unsupported flags, and applies priority rules.
- `handler/`: extracts the correct argument from `va_list` and prepares a normalized internal representation.
- `utils/`: renders text or numbers and flushes buffered output.

This decomposition is justified because each stage has one clear responsibility:

- parsing should not know how a number is printed,
- printing should not know how the format string is scanned,
- handlers should not duplicate flag validation logic,
- the output layer should not care which conversion produced the bytes.

That separation reduces branching complexity and avoids having the same rule duplicated in several specifiers.

### Core data structures
The implementation relies on a few small internal structures:

`t_format`
- stores the parsed view of one conversion.
- contains `flags`, `width`, `precision`, and `specifier`.
- acts as the normalized contract between parsing and formatting.

`t_context`
- stores the live execution state of the whole call to `ft_printf`.
- contains the active `va_list`, the output buffer, current buffer position, total length written so far, error state, and the current `t_format`.
- centralizes state so helper functions do not need long parameter lists.

`t_specifier`
- represents one entry in the specifier dispatch table.
- contains the specifier character, its handler function, and the mask of allowed flags.
- makes the table the single source of truth for supported conversions.

`t_numfmt`
- provides a normalized numeric view for number printing.
- contains the unsigned numeric value, digit base, optional sign string, and optional prefix string.
- lets one generic number printer handle decimal, unsigned, hexadecimal, uppercase hexadecimal, and pointer output.

`t_lengths`
- groups derived numeric layout data such as digit length, precision zeros, and total padding.
- avoids recomputing formatting lengths while rendering numbers.

### Why bitmasks for flags
Flags are stored in a bitmask rather than in separate booleans.

This choice is justified because:

- checking whether a flag is active is constant-time and compact,
- masking unsupported flags per specifier is trivial,
- applying priority rules becomes simple bitwise logic,
- the structure remains small and easy to pass around.

For this project, a bitmask is a better fit than a larger structure of independent booleans because flags are a finite, stable set and many operations are rule-based combinations of active bits.

### Why a dispatch table
The dispatch table in `dispatcher/get_spec_table.c` is one of the key design decisions.

It is justified because it keeps three related facts in one place:

- which specifiers exist,
- which function handles each one,
- which flags are valid for each specifier.

Without this table, those rules would likely be spread across several `if`/`else` or `switch` blocks, increasing the chance of inconsistencies. With the table, adding or auditing support is simpler and less error-prone.

### Why a fixed output buffer
The project uses a fixed internal buffer (`PF_BUF_CAP = 4096`) and writes through `buffer_manager.c`.

This choice is justified because:

- repeated direct `write()` calls for every character are inefficient,
- the project does not require dynamic output storage,
- a fixed stack-allocated buffer keeps memory management simple,
- flush logic can centralize both I/O and runtime error detection.

A dynamic string builder would be more complex and unnecessary for the project scope. Buffering before `write()` gives a good tradeoff between simplicity and efficiency.

### Why the numeric formatting algorithm works this way
Number formatting is handled in two phases:

1. compute all layout lengths,
2. emit sign, prefix, zeros, digits, and padding in the correct order.

This is preferable to printing incrementally without planning because width, zero-padding, precision-padding, sign placement, and prefixes interact with each other. Precomputing the layout guarantees stable ordering and makes the result easier to verify.

Internally, signed integers are normalized into:

- a sign string (`"-"`, `"+"`, `" "`, or empty),
- an unsigned magnitude,
- a target digit alphabet (`0123456789`, lowercase hex, uppercase hex),
- an optional prefix (`0x`, `0X`, or empty).

This lets one generic printer cover all numeric cases.

### Why `parse_number_sat` saturates to `INT_MAX`
Width and precision are parsed with a saturating helper instead of naive unchecked accumulation.

This is justified because:

- the public return type of `ft_printf` is `int`,
- absurdly large format widths should not cause parsing overflow,
- clamping keeps behavior predictable and avoids undefined arithmetic during parsing.

The implementation therefore treats extremely large numeric width or precision inputs as capped values instead of letting them overflow silently.

## Technical Overview
Project structure:

```text
inc/
  num_fmt.h
  number_printer_lengths.h
  parse_number_sat.h
  spec_table.h
src/
  dispatcher/
  handler/
  parser/
  utils/
libft/
libftprintf.h
Makefile
README.md
```

Formatting flow:

1. `ft_printf` initializes the execution context.
2. The format string is scanned left to right.
3. Literal characters are buffered directly.
4. When `%` is found, the parser fills `t_format`.
5. The dispatcher masks invalid flags and applies priority rules.
6. The selected handler reads the next variadic argument.
7. The printer emits the formatted representation into the buffer.
8. The buffer flushes to `write()` when full and once at the end.

## Runtime Behavior and Error Handling
- Output is buffered before being sent to `write(1, ...)`.
- If `write()` fails, `ft_printf` returns `-1`.
- If the accumulated output length would overflow `INT_MAX`, `ft_printf` returns `-1`.
- A final flush is executed before returning.

## Local Test Harness (`main.c`)
The repository currently includes a local comparison harness in `main.c`.

Its purpose is purely developmental:

- compare `printf` and `ft_printf` side by side,
- compare return values,
- exercise edge cases by category,
- make manual regression checks faster.

The file is organized into visual blocks:

- basic literals and chars,
- strings,
- signed integers,
- unsigned and hexadecimal numbers,
- pointers,
- mixed integration-style sequences.

Two helper macros are used:

- `RUN_CASE`: for format strings that can safely remain string literals.
- `RUN_CASE_DYNAMIC`: for selected test formats stored in variables so that local compiler warnings about ignored or overridden libc format flags do not block the build under `-Werror`.

Important note:

- `main.c` is a local helper, not part of the core library.
- it is safe to keep for local work,
- but if it uses the original libc `printf`, it should be removed from the deliverable repository before final submission if that is required by the evaluation rules.

## Limitations
- No length modifiers are implemented (`hh`, `h`, `l`, `ll`, etc.).
- No floating-point conversions are implemented (`%f`, `%e`, `%g`, etc.).
- `*` is not supported for width or precision.
- Behavior for invalid format strings or mismatched variadic argument types is outside the project scope.

## Resources
### Classical references
- `man 3 printf`
- `man 3 stdarg`
- Kernighan and Ritchie, *The C Programming Language*
- ISO C documentation for variadic functions and formatted output behavior
- 42 subject and peer evaluation criteria for `ft_printf`

### AI usage
AI assistance was used as a support tool during development and review, not as a substitute for implementation ownership.

It was used for:

- reviewing architecture and code organization,
- identifying edge cases around buffering, flag priority, and runtime error paths,
- improving the local comparison test coverage in `main.c`,
- refining the Makefile structure and dependency handling,
- drafting and polishing project documentation.

The final design decisions, implementation choices, code integration, and validation were manually reviewed and executed in the project itself.
