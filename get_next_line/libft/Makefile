# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 13:00:32 by qdiaz             #+#    #+#              #
#    Updated: 2016/01/23 14:54:11 by qdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -I.

SRCS = includes/ft_atoi.c\
	includes/ft_isalnum.c\
	includes/ft_isalpha.c\
	includes/ft_isascii.c\
	includes/ft_isdigit.c\
	includes/ft_putchar.c\
	includes/ft_putnbr.c\
	includes/ft_putstr.c\
	includes/ft_strcat.c\
	includes/ft_strchr.c\
	includes/ft_strcmp.c\
	includes/ft_strcpy.c\
	includes/ft_strdup.c\
	includes/ft_strlen.c\
	includes/ft_strncat.c\
	includes/ft_strncmp.c\
	includes/ft_strncpy.c\
	includes/ft_strnstr.c\
	includes/ft_strstr.c\
	includes/ft_tolower.c\
	includes/ft_toupper.c\
	includes/ft_strrchr.c\
	includes/ft_bzero.c\
	includes/ft_memset.c\
	includes/ft_isprint.c\
	includes/ft_memccpy.c\
	includes/ft_memchr.c\
	includes/ft_memcmp.c\
	includes/ft_memcpy.c\
	includes/ft_memmove.c\
	includes/ft_strlcat.c\
	includes/ft_putstr.c\
	includes/ft_putchar.c\
	includes/ft_putnbr.c\
	includes/ft_putendl.c\
	includes/ft_putstr_fd.c\
	includes/ft_putchar_fd.c\
	includes/ft_putnbr_fd.c\
	includes/ft_putendl_fd.c\
	includes/ft_strclr.c\
	includes/ft_strequ.c\
	includes/ft_strnequ.c\
	includes/ft_strnew.c\
	includes/ft_strdel.c\
	includes/ft_memalloc.c\
	includes/ft_memdel.c\
	includes/ft_striter.c\
	includes/ft_striteri.c\
	includes/ft_strmap.c\
	includes/ft_strmapi.c\
	includes/ft_strtrim.c\
	includes/ft_strsplit.c\
	includes/ft_strsub.c\
	includes/ft_strjoin.c\
	includes/ft_itoa.c\
	includes/ft_lstadd.c\
	includes/ft_lstdelone.c\
	includes/ft_lstdel.c\
	includes/ft_lstnew.c\
	includes/ft_lstiter.c\
	includes/ft_lstmap.c\
	includes/ft_isspace.c\
	includes/ft_strrev.c\
	includes/ft_swap.c\
	includes/ft_strupcase.c\
	includes/ft_strdowncase.c\
	includes/ft_strcdup.c\
	includes/ft_strndup.c\
	includes/ft_strclen.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $?

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
