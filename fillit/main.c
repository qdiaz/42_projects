/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:49:54 by adu-pelo          #+#    #+#             */
/*   Updated: 2015/12/18 16:32:55 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		ft_check_ac(int ac)
{
	if (ac != 2)
	{
		ft_error();
		return (FALSE);
	}
	return (TRUE);
}

void	print_map(int **map)
{
	int i;
	int j;

	i = 0;
	while (map[i][0] != -1)
	{
		j = 0;
		while (map[i][j] != -1)
		{
			if (map[i][j] == 0)
				ft_putchar('.');
			else
				ft_putchar(map[i][j] + '@');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	int l;
	int c;
	char *buffer;
	int		min_sqr;
	int		cnt_tetri;
	int		***tetri;
	int		**map;

	l = 0;
	c = 0;
	ft_check_ac(ac);
	buffer = ft_get_file(av[1]);
	ft_check_file(buffer);
	cnt_tetri = ft_count_tetri(buffer);
	tetri = ft_split_tetri(buffer);
	if (ft_check_shape(tetri, cnt_tetri, l, c) == TRUE)
	{
		ft_split_tetri(ft_get_file(av[1]));
		min_sqr = ft_define_min_sqr(cnt_tetri * 4);
		if (!(map = ft_create_map(min_sqr)))
			ft_error();
		print_map(resol(tetri, cnt_tetri));
	}
	else
		ft_error();
	return (0);
}
