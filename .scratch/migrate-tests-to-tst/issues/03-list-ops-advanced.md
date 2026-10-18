# 03: List ops advanced: lstadd_front, lstiter, lstmap

**What to build:** Convert 3 linked-list test files from theft to tst. `lstadd_front` verifies size progression (0→1→2→3) and order; `lstiter` counts callback invocations (expects exactly 3); `lstmap` maps over a 3-element list, preserves result structure, and clears inputs without leaking. Each needs careful conversion of property logic that inspects internal list state.

**Blocked by:** 01

**Status:** ready-for-agent

- [ ] `ft_lstadd_front_test.c` compiles with tst and passes
- [ ] `ft_lstiter_test.c` compiles with tst and passes
- [ ] `ft_lstmap_test.c` compiles with tst and passes