/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:51:38 by adu-pelo          #+#    #+#             */
/*   Updated: 2015/12/17 18:06:38 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*ft_get_coord(int **tetri)
{
	int		*coord;
	int		x;
	int		y;
	int		j;

	if ((coord = malloc(sizeof(int) * 8)) == NULL)
		return (NULL);
	x = 0;
	j = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetri[x][y] > 0)
			{
				coord[j] = x;
				coord[j + 1] = y;
				j += 2;
			}
			y++;
		}
		x++;
	}
	return (coord);
}

static void		placement(int **tab, int **resol, int line, int col)
{
	int		*x;
	int		j;

	j = 0;
	x = ft_get_coord(tab);
	while (j < 8)
	{
		resol[line + (x[j] - x[0])][col + (x[j + 1] - x[1])] =
			tab[x[j]][x[j + 1]];
		j += 2;
	}
}

static void		desempiler(int **resol, int piece_nb)
{
	int		i[2];

	i[0] = 0;
	while (resol[i[0]][0] != -1)
	{
		i[1] = 0;
		while (resol[0][i[1]] != -1)
		{
			if (resol[i[0]][i[1]] == piece_nb + 1)
				resol[i[0]][i[1]] = 0;
			i[1]++;
		}
		i[0]++;
	}
}

static int		check_placement(int **tab, int **resol, int line, int col)
{
	int		*x;
	int		j;

	x = ft_get_coord(tab);
	j = 0;
	while (j < 8)
	{
		if (resol[line + (x[j] - x[0])][col + (x[j + 1] - x[1])] != 0 ||
				col + (x[j + 1] - x[1]) < 0)
			return (0);
		j += 2;
	}
	return (1);
}

int				recursive_placement(int ***tab, int **resol, int piece_nb)
{
	int		i[2];

	if (tab[piece_nb] == NULL)
		return (1);
	i[0] = 0;
	while (resol[i[0]][0] != -1)
	{
		i[1] = 0;
		while (resol[0][i[1]] != -1)
		{
			if (resol[i[0]][i[1]] == 0)
				if (check_placement(tab[piece_nb], resol, i[0], i[1]) == 1)
				{
					placement(tab[piece_nb], resol, i[0], i[1]);
					if (recursive_placement(tab, resol, piece_nb + 1) == 1)
						return (1);
					desempiler(resol, piece_nb);
				}
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}
