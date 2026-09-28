# ft_itoa

> Sources: 42 school libft subject v19.3, 2026-09-28
> Raw: [libft-subject](../../raw/project-overview/libft-subject.md)
> Updated: 2026-09-28

## Overview

`ft_itoa` allocates memory (using `malloc(3)`) and returns a string representing the integer received as an argument. Negative numbers must be handled. Prototype: `char *ft_itoa(int n)`.

## Parameters

- **n** — The integer to convert.

## Return value

The string representing the integer. NULL if the allocation fails.

## Implementation

Status: **not yet implemented** — `ft_itoa.c` is a stub.

Planned external functions (not yet in code): direct `malloc` only, which the subject allows for this function. No Part 1 reimplementation is needed — the conversion is manual digit extraction.

## See Also

- [ft_substr](ft-substr.md), [ft_strjoin](ft-strjoin.md) — sibling allocation-based string builders
