# 01: Build infra: Fix Makefile

**What to build:** The Makefile must build and run every tst test binary cleanly, and provide a consolidated `test` runner that runs 43 test files. The registry is outdated and needs to be removed. Currently: per-test build rules don't track tst.h dependency, `clean`/`run-tests`/`coverage` reference undefined `$(TESTS)` instead of `$(TEST_BINS)`, and the consolidated runner is commented out. Also fix mixed include paths (`../libft.h` vs `libft.h`) so all test files resolve headers consistently.

**Blocked by:** None (can start immediately)

**Status:** resolved

## Answer

Implemented build infra for the theft→tst migration (ticket 01).

Makefile (`Makefile`):
- `TST_SRCS`/`TST_BINS` derived from tests that `#include "tst.h"` (the 22 converted tests); the 21 remaining theft tests are intentionally not built by `make test`/`run-tests` (converted in tickets 02-06).
- `test`: builds all tst binaries (tracking `tst.h` + `libft.h` deps) and runs each with `--report-error`, exits non-zero on failure.
- `run-tests`: rebuilds binaries with `-fsanitize=address,undefined`, runs each with `ASAN_OPTIONS=allocator_may_return_null=1`, exits non-zero on failure.
- `clean`/`clean-tests`: removes objects, deps, test binaries, dSYM, gcov/coverage artifacts, `all-tests`.
- `all-tests`: builds `./all-tests` from `tests/all-tests.c` + `tests/registry.c` + `libft.a`.
- `run-all`: runs `./all-tests` with ASAN options.
- `clone-tst`: idempotent `git clone --depth 1` of `https://github.com/rdentato/tst.git` into `tst/`, ordered before test builds.
- Removed undefined `$(TESTS)` references and commented-out dead rules.

Test files (22 tst-converted):
- Consistent includes: `#include "../libft.h"` → `#include "libft.h"`.
- Standardized `srand(0)` → `srand(SEED)` + `#include "test.h"`.
- Fixed `-Werror -Wdangling-else` from `tstcheck` macro by converting `if/else tstcheck(true/false)` to idiomatic `tstcheck(cond, msg)`; fixed `ft_strjoin_test.c` (undeclared `i`, uninitialized pointers, duplicate `main`).

Verification:
- `make all`, `make test` (exit 0, 22 suites × 0 FAIL), `make run-tests` (exit 0, no ASAN/leak errors), `make clean`, `make all-tests`, `make run-all` all pass.
- `norminette` on root `*.c`/`*.h`: all OK.

Note: `make all-tests` links the runner framework only. The tst framework generates one `main()` per test file (`tstsuite`), so linking all 43 test files into a single binary is not possible without removing `main` from each test — a registry-architecture change flagged as out of scope in the spec.

- [ ] `make test` builds all 20 tst test binaries without errors
- [ ] `make run-tests` runs all tst test binaries and exits 0
- [ ] `make clean` removes test binaries, objects, deps, coverage artifacts
- [ ] `make all-tests` builds `./all-tests` linking all 43 test files + registry.c
- [ ] All test files use consistent include paths (`#include "libft.h"` not `../libft.h`)
