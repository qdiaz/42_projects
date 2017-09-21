# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 15:40:41 by qdiaz             #+#    #+#              #
#    Updated: 2017/09/21 15:43:26 by qdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

C_DIR =	src
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)
C_FILES = $(shell find $(C_DIRS) -type f -follow -print | grep "\.c")

TEST_FILES = tests/malloc_main.c
TEST_BIN = test_malloc

O_DIR =	.tmp/obj
O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
	O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

FLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -Ilibft/include
LIB = -Llibft -lft

.SILENT:

all: $(NAME)

$(NAME): $(O_FILES)
	echo "\\033[1;34mCompiling LIBFT...\\033[0;39m"
	make -C libft
	gcc $(FLAGS) -shared $^ $(LIB) -o $@
	ln -fs $(NAME) libft_malloc.so
	echo "\\033[32m$(NAME) has been created !\\033[0;39m"

test: $(O_FILES)
	make -C libft
	$(CC) $(FLAGS) $^ $(TEST_FILES) $(INCLUDES) $(LIB) -o $(TEST_BIN)

$(O_DIR)%.o: $(C_DIR)%.c
	mkdir -p $(O_DIRS) $(O_DIR)
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $<
	echo "\\033[1;34mGenerating objects... Please wait\\033[0;39m"

clean:
	make clean -C libft
	rm -rf $(O_DIR)
	echo "\\033[31mobjects files has been removed !\\033[0;39m"

fclean: clean
	make fclean -C libft
	rm $(NAME) || true
	rm libft_malloc.so
	rm -rf .tmp/
	echo "\\033[31m$(NAME) has been removed !\\033[0;39m"

re: fclean all

.PHONY: clean all fclean re
