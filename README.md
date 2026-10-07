_This project has been created as part of the 42 curriculum by choolau_

## Description

 clearly presents the project, including its goal and a brief overview.

## Instructions

Build the library:

```sh
make            # build libft.a
```

Housekeeping and reporting:

```sh
make clean     # remove objects, deps, test binaries, coverage artifacts
make fclean    # clean + remove libft.a
make re        # fclean + all
```

### Extra Instructions

Per-function property tests (each `tests/ft_*_test.c` builds to `./ft_*_test` with ASan+UBSan):

```sh
make clone-theft   # one-time: fetch theft test dependency
make test          # build all per-function test binaries
make run-tests     # build + run each test binary (ASAN_OPTIONS=allocator_may_return_null=1)
./ft_split_test    # run a single test binary
```

Consolidated runner:

```sh
make all-tests   # build ./all-tests from all tests/*.c (defines ALL_TESTS)
make run-all     # build + run ./all-tests
```

Housekeeping and reporting:

```sh
make coverage  # run-tests + gcov reports into coverage/
make wipe      # fclean + remove docs tests raw wiki skills-lock.json (destructive)
```

## Resources

Refer to [wiki](wiki/index.md)

C Property Based Testing Library - [Theft](https://github.com/silentbicycle/theft)

### Ai Usage

- Generate the files and tests files with placeholder methods
- Implement the registry for testing with `Makefile` modifications
- `ft_memmove` needed help to generate forward and backwards overlapping test cases
- `ft_strnstr` needed help to use double pointers to find overlapping needle
- `ft_calloc_test` ASAN_OPTIONS in `Makefile`
