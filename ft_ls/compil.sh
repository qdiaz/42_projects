make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/ -o ft_ls.o -c ft_ls.c
clang -o ft_ls ft_ls.o -I libft/ -L libft/ -lft
rm -f ft_ls.o
echo "\033[32mft_ls was created\033[0m"
