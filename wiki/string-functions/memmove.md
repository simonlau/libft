# memmove

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-memmove-3.md
> Updated: 2026-08-14

## Overview

The `memmove()` function copies `n` bytes from one memory area to another, correctly handling overlapping memory areas. It is part of the Standard C library (`<string.h>`) and is thread-safe.

## Description

`memmove()` is similar to `memcpy()`, but the memory areas may overlap. The function is standardized in C11 and POSIX.1-2008, with historical roots in C89, SVr4, and 4.3BSD.

Key points:
- Copies `n` bytes from `src` to `dest`
- Memory areas may overlap (unlike `memcpy`)
- Returns a pointer to `dest`
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Preferred over `memcpy()` when overlap is possible
