# 04: String + heap: strtrim, split, substr, strmapi, striteri, calloc, strdup

**What to build:** Convert 7 property-based test files from theft to tst. `strtrim` strips `set` chars from both ends of `s1` and compares against an oracle; `split` splits on delimiter `c` and verifies the resulting array; `substr` extracts a substring with start/len bounds; `strmapi` applies a per-char function and checks the result; `striteri` modifies in place and verifies; `calloc` compares zeroed allocation against libc; `strdup` compares against libc strdup. 1000 random trials each.

**Blocked by:** 01

**Status:** ready-for-agent

- [ ] `ft_strtrim_test.c` compiles with tst and passes
- [ ] `ft_split_test.c` compiles with tst and passes
- [ ] `ft_substr_test.c` compiles with tst and passes
- [ ] `ft_strmapi_test.c` compiles with tst and passes
- [ ] `ft_striteri_test.c` compiles with tst and passes
- [ ] `ft_calloc_test.c` compiles with tst and passes
- [ ] `ft_strdup_test.c` compiles with tst and passes