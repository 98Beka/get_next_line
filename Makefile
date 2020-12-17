NAME = tst

COMPILER = gcc
FLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=16

SRC = \
		get_next_line.c \
		get_next_line_utils.c \

H = get_next_line.h

all:
	$(COMPILER) $(FLAGS) $(SRC)  main.c

c:
	rm a.out

.PHONY: all c
