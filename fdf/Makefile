# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/19 11:56:04 by qdiaz             #+#    #+#              #
#    Updated: 2016/06/01 15:15:57 by qdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = main.c color.c draw.c parsing.c tools.c event_test.c
OBJ = $(SRC:.c=.o)
LIB = -L./libft -lft -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror

.SILENT:

$(NAME): $(OBJ)
	echo "\\033[1;34mGenerating objects... Please wait\\033[0;39m"
	make -C ./libft
	echo "\\033[36mcompiling $(NAME)...\\033[0;39m"
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
	echo "\\033[32m$(NAME) has been created !\\033[0;39m"

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C libft/ clean
	echo "\\033[31mobjects files has been removed !\\033[0;39m"

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	echo "\\033[31m$(NAME) has been removed !\\033[0;39m"

re: fclean $(NAME)

.PHONY : all clean fclean re
