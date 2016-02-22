# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/22 13:54:02 by qdiaz             #+#    #+#              #
#    Updated: 2016/02/22 14:03:21 by qdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ./ft_ls

SRCS = 	display.c\
		format_path.c\
		option.c\
		padding.c\
		size.c\
		sort_lst.c\
		sort_tab.c\
		tool.c\
		main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@gcc $(OBJS) -o $(NAME) -L libft/ -lft

%.o: %.c
	gcc -Wall -Werror -Wextra -c $^

clean:
	@make -C libft/ clean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(OBJS)

re: fclean $(NAME)
