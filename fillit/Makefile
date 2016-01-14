# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 10:35:28 by qdiaz             #+#    #+#              #
#    Updated: 2016/01/12 15:30:43 by adu-pelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ./fillit

SRCS = 	fillit.c\
		ft_get_file.c\
		ft_check_file.c\
		ft_count_tetri.c\
		ft_error.c\
		ft_create_map.c\
		ft_resolve.c\
		ft_resolve_tools.c\
		ft_split_tetri.c\

LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		gcc -o $(NAME) $(SRCS) $(LIBFT) -I.

%.o: %.c
	gcc -Wall -Werror -Wextra -c $^

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) fillit.h.gch

re: fclean all

