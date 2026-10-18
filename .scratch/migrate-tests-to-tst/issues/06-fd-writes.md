# 06: fd writes: putchar_fd, putstr_fd, putendl_fd, putnbr_fd

**What to build:** Convert 4 file-descriptor test files from theft to tst. All use the same pipe-oracle pattern: create a pipe, call the ft_*_fd function to write, read back from the pipe fd, compare to snprintf-constructed expected output. `putchar_fd` writes a single byte; `putstr_fd` writes a string; `putendl_fd` writes string + '\n'; `putnbr_fd` writes an integer. Each needs careful porting of the IO setup, read loop, and expected string construction. 1000 trials each with random int/char inputs.

**Blocked by:** 01

**Status:** ready-for-agent

- [ ] `ft_putchar_fd_test.c` compiles with tst and passes
- [ ] `ft_putstr_fd_test.c` compiles with tst and passes
- [ ] `ft_putendl_fd_test.c` compiles with tst and passes
- [ ] `ft_putnbr_fd_test.c` compiles with tst and passes