##
## Makefile
##
## Licensed under GNU GPL v3
##

.PHONY: all clean fclean re

NAME := ed

RM := rm -f

BIN_DIR := ./bin
SRC_DIR := ./source
HDR_DIR := ./include
OBJ_DIR := $(BIN_DIR)/obj

SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(SRCS:.c=.o)
LIBS := -lunixlib

WARNINGS := -Wall -Wextra -Werror -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline -Wno-long-long -Wuninitialized -Wstrict-prototypes

CFLAGS := -std=c89 -O2 -g -I$(HDR_DIR) $(WARNINGS) $(LIBS)

all: $(OBJS)
	-@mkdir -p $(BIN_DIR) $(OBJ_DIR)
	mv $(OBJS) $(OBJ_DIR)
	cc $(OBJ_DIR)/*.o $(CFLAGS) -o $(BIN_DIR)/$(NAME)

clean:
	-@$(RM) $(OBJ_DIR)/*.o

fclean: clean
	-@$(RM) $(BIN_DIR)/$(NAME)

re: fclean all
