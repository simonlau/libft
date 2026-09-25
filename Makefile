# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/07 15:20:10 by simon.lau         #+#    #+#              #
#    Updated: 2026/09/25 13:55:40 by simon.lau        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
AR := ar
ARFLAGS := rcs

THEFT_URL := https://github.com/silentbicycle/theft.git
THEFT_DIR := theft

CFLAGS := -Wall -Wextra -Werror -I$(THEFT_DIR)/inc -I.
# CFLAGS += -lbsd
CFLAGS += -g3 -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover=all

TESTS := $(basename $(notdir $(wildcard tests/*_test.c)))
SRCS := $(wildcard ft_*.c)
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
NAME := libft.a

.PHONY: all clean fclean re test run-tests coverage clone-theft wipe all-tests run-all

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

test: $(TESTS)

%_test: %.c tests/%_test.c tests/registry.c $(THEFT_DIR)/build/libtheft.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

all-tests: tests/all-tests.c tests/registry.c $(wildcard tests/ft_*.c) $(NAME) $(THEFT_DIR)/build/libtheft.a
	$(CC) $(CFLAGS) -Itests -DALL_TESTS -o $@ tests/all-tests.c tests/registry.c $(wildcard tests/ft_*.c) $(NAME) $(THEFT_DIR)/build/libtheft.a -lm

run-all: all-tests
	./all-tests

$(THEFT_DIR)/build/libtheft.a:
	$(MAKE) -C $(THEFT_DIR)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clone-theft:
	git clone --depth 1 $(THEFT_URL) $(THEFT_DIR)

clean:
	rm -f $(OBJS) $(DEPS) $(TESTS)
	rm -f *.gcda *.gcno tests/*.gcda tests/*.gcno
	rm -rf $(TESTS:=.dSYM) all-tests all-tests.dSYM coverage .coverage

fclean: clean
	rm -f $(NAME)

re: fclean all

run-tests: $(TESTS)
	@for test in $(TESTS); do \
		echo "Running $$test..."; \
		./$$test || exit 1; \
	done

coverage: run-tests
	@mkdir -p coverage
	@gcov -p -o . $(SRCS) 2>/dev/null || true
	@mv *.gcov coverage/ 2>/dev/null || true
	@echo "Coverage reports generated in coverage/"

wipe: fclean
	rm -rf docs tests raw wiki
	rm skills-lock.json
