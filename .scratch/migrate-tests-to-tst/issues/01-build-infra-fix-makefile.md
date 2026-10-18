# 01: Build infra: Fix Makefile

**What to build:** The Makefile must build and run every tst test binary cleanly, and provide a consolidated `test` runner that runs 43 test files. The registry is outdated and needs to be removed. Currently: per-test build rules don't track tst.h dependency, `clean`/`run-tests`/`coverage` reference undefined `$(TESTS)` instead of `$(TEST_BINS)`, and the consolidated runner is commented out. Also fix mixed include paths (`../libft.h` vs `libft.h`) so all test files resolve headers consistently.

**Blocked by:** None (can start immediately)

**Status:** ready-for-agent

- [ ] `make test` builds all 20 tst test binaries without errors
- [ ] `make run-tests` runs all tst test binaries and exits 0
- [ ] `make clean` removes test binaries, objects, deps, coverage artifacts
- [ ] `make all-tests` builds `./all-tests` linking all 43 test files + registry.c
- [ ] All test files use consistent include paths (`#include "libft.h"` not `../libft.h`)
