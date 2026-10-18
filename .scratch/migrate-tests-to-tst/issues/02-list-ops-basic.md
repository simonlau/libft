# 02: List ops basic: lstnew, lstsize, lstlast, lstadd_back, lstdelone, lstclear

**What to build:** Convert 6 linked-list test files from theft to tst. Each tests a single list function against a property oracle: `lstnew` creates a node with correct content/next; `lstsize` counts correctly after adds; `lstlast` returns the right node; `lstadd_back` appends to tail; `lstdelone` frees a node without crashing; `lstclear` empties the list. Straightforward conversion of `theft_propfunN` to `tstcase` loops over 2000 random char inputs.

**Blocked by:** 01

**Status:** ready-for-agent

- [ ] `ft_lstnew_test.c` compiles with tst and passes
- [ ] `ft_lstsize_test.c` compiles with tst and passes
- [ ] `ft_lstlast_test.c` compiles with tst and passes
- [ ] `ft_lstadd_back_test.c` compiles with tst and passes
- [ ] `ft_lstdelone_test.c` compiles with tst and passes
- [ ] `ft_lstclear_test.c` compiles with tst and passes