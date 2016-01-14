/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:06:40 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/01/12 15:41:40 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE 545
# define FALSE 0
# define TRUE 1

int		ft_define_min_sqr(int nb_tetri);
int		***ft_split_tetri(char *str);
char	*ft_get_file(char *file);
int		ft_count_tetro(char *str);
int		ft_check_file(char *str);
void	ft_error(void);
int		ft_count_tetri(char *str);
int		**ft_create_map(int size);
int		**ft_resol(int ***tab, int nb_tetri);
int		ft_recursive_resol(int ***tab, int **resol, int piece_nb);

#endif
