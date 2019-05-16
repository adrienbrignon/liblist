##
## EPITECH PROJECT, 2018
## liblist
## File description:
## The library build instructions.
##

CC = gcc
CFLAGS = -pipe -O2 -Iinclude
CFLAGS += -Wall -Wextra -Wshadow -Wno-unused-parameter -Wuninitialized
LDFLAGS = -L.
LDLIBS = -llist -lcriterion

NAME = liblist.a

SRCS = $(wildcard src/*.c) $(wildcard src/**/*.c)
OBJS = $(SRCS:.c=.o)

TEST_NAME = unit-tests

TEST_SRCS = $(wildcard test/*.c) $(wildcard test/**/*.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)

all: $(NAME)

$(NAME): CFLAGS += $(TEST_FLAGS)
$(NAME): $(OBJS)
	$(AR) rcs $@ $^

$(TEST_NAME): $(NAME) $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_FLAGS) -o $@ $(TEST_OBJS) $(LDFLAGS) $(LDLIBS)

test: TEST_FLAGS += -coverage
test: $(TEST_NAME)
	./$(TEST_NAME)

clean:
	$(RM) src/*.o src/**/*.o src/*.gc* src/**/*.gc*
	$(RM) test/*.o test/**/*.o test/*.gc* test/**/*.gc*

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

re: fclean all

.PHONY: all test clean fclean re
