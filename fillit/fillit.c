/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:49:54 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/01/12 15:54:18 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_ac(int ac)
{
	if (ac != 2)
		ft_error();
	return (TRUE);
}

static void	ft_print_map(int **map)
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

static void	ft_free_tetri(int ***tetri, int cnt_tetri)
{
	int i;
	int l;

	i = 0;
	while (i < cnt_tetri)
	{
		l = 0;
		while (l < 4)
		{
			free(tetri[i][l]);
			tetri[i][l] = NULL;
			l++;
		}
		free(tetri[i]);
		tetri[i] = NULL;
		i++;
	}
	free(tetri);
	tetri = NULL;
}

static void	ft_free_map(int **map)
{
	int l;

	l = 0;
	while (*map[l] != -1)
	{
		free(map[l]);
		map[l] = NULL;
		l++;
	}
	free(map[l]);
	map[l] = 0;
	free(map);
	map = NULL;
}

int			main(int ac, char **av)
{
	char	*buffer;
	int		cnt_tetri;
	int		***tetri;
	int		**map;

	ft_check_ac(ac);
	buffer = ft_get_file(av[1]);
	ft_check_file(buffer);
	cnt_tetri = ft_count_tetri(buffer);
	tetri = ft_split_tetri(buffer);
	map = ft_resol(tetri, cnt_tetri);
	ft_print_map(map);
	ft_free_map(map);
	map = NULL;
	ft_free_tetri(tetri, cnt_tetri);
	tetri = NULL;
	return (0);
}
