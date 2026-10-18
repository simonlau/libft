# 05: Complex string: ft_strnstr

**What to build:** Convert the most complex test file from theft to tst. The original uses a custom allocator generating alphabets of different sizes (1-byte {a,b} vs 8-byte full byte range), 4 property variants (spec-vs-system oracle, two sweep variants with different alphabets, ft-vs-system diff), plus fuzz sweep. Requires porting the full theft config machinery (type info, alloc hook, trial hooks) to tst's manual test loop. 1000 trials each.

**Blocked by:** 01

**Status:** ready-for-agent

- [ ] `ft_strnstr_test.c` compiles with tst
- [ ] All 4 property variants pass across 1000 trials
- [ ] Custom allocator logic (alphabet bits, hay allocation) preserved correctly