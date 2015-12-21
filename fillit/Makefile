# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 10:35:28 by qdiaz             #+#    #+#              #
#    Updated: 2015/12/18 11:54:53 by qdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./fillit

SRCS = main.c\
	ft_get_file.c\
	ft_check_file.c\
	ft_check_shape.c\
	ft_error.c\
	ft_create_map.c\
	ft_resolve.c\
	ft_resolve_tools.c\
	ft_split_tetri.c\
	ft_bzero.c\
	ft_memset.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_strlen.c\
	ft_strnew.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
				gcc -o $(NAME) $(SRCS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) fillit.h.gch

re: fclean all

