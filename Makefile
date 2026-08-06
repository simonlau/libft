CC=cc
CFLAGS = -Wall -Wextra -Werror -I$(THEFT_DIR)/inc -I.
CFLAGS += -g3 -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover=all

THEFT_URL = https://github.com/silentbicycle/theft.git
THEFT_DIR = theft

TESTS := $(basename $(notdir $(wildcard tests/*_test.c)))
SRCS = $(wildcard ft_*.c)
OBJS = $(SRCS:.c=.o)
NAME = libft.a

.PHONY: all clean fclean re test clone-theft

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

test: $(TESTS)

%_test: %.c tests/%_test.c $(THEFT_DIR)/build/libtheft.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(THEFT_DIR)/build/libtheft.a:
	$(MAKE) -C $(THEFT_DIR)

clone-theft:
	git clone --depth 1 $(THEFT_URL) $(THEFT_DIR)

clean:
	rm -f $(OBJS)
	rm -f $(TESTS)
	rm -rf *_test.dSYM

fclean: clean
	rm -f $(NAME)

re: fclean all
