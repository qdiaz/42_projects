# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/19 11:56:04 by qdiaz             #+#    #+#              #
#    Updated: 2016/04/20 15:51:22 by qdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = main.c	tools.c		ft_param.c		free.c\
	ft_setenv.c	ft_unsetenv.c	ft_cd.c		tools2.c\
	env.c	fork.c	tools3.c	ft_strsplit_ws.c\
	env2.c	tools4.c	prompt.c	fork2.c
OBJ = $(SRC:.c=.o)
LIB = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean $(NAME)

.PHONY : all clean fclean re
