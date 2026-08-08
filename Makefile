# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/07 15:20:10 by simon.lau         #+#    #+#              #
#    Updated: 2026/08/07 15:20:11 by simon.lau        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
AR := ar
ARFLAGS := rcs

THEFT_URL := https://github.com/silentbicycle/theft.git
THEFT_DIR := theft

CFLAGS := -Wall -Wextra -Werror -I$(THEFT_DIR)/inc -I.
CFLAGS += --coverage -g3 -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover=all

TESTS := $(basename $(notdir $(wildcard tests/*_test.c)))
SRCS := $(wildcard ft_*.c)
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
NAME := libft.a

.PHONY: all clean fclean re test run-tests coverage clone-theft

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

test: $(TESTS)

%_test: %.c tests/%_test.c $(THEFT_DIR)/build/libtheft.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(THEFT_DIR)/build/libtheft.a:
	$(MAKE) -C $(THEFT_DIR)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clone-theft:
	git clone --depth 1 $(THEFT_URL) $(THEFT_DIR)

clean:
	rm -f $(OBJS) $(DEPS) $(TESTS)
	rm -f *.gcda *.gcno
	rm -rf $(TESTS:=.dSYM) coverage .coverage

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
