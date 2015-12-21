/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:06:40 by adu-pelo          #+#    #+#             */
/*   Updated: 2015/12/18 14:26:04 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE 545
# define FALSE 0
# define TRUE 1

int		ft_define_min_sqr(int nb_tetri);
int		ft_check_shape(int ***tetri, int nb_tetri, int l, int c);
int		***ft_split_tetri(char *str);
char	*ft_get_file(char *file);
int		ft_count_tetro(char *str);
int		ft_check_file(char *str);
void	ft_error(void);
int		ft_count_tetri(char *str);
int		**ft_create_map(int size);
void	print_map(int **map);
int		**resol(int ***tab, int nb_tetri);
int		recursive_placement(int ***tab, int **resol, int piece_nb);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
void	ft_putstr(char const *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);

#endif
