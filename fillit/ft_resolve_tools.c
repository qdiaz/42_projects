/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:51:38 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/01/12 15:48:09 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*ft_get_coord(int **tetri)
{
	int		*coord;
	int		j;
	int		l;
	int		c;

	l = 0;
	j = 0;
	if (!(coord = malloc(sizeof(int) * 8)))
		return (NULL);
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (tetri[l][c] > 0)
			{
				coord[j] = l;
				coord[j + 1] = c;
				j += 2;
			}
			c++;
		}
		l++;
	}
	return (coord);
}

static void		ft_place(int **tab, int **resol, int line, int col)
{
	int		*coord;
	int		j;

	j = 0;
	coord = ft_get_coord(tab);
	while (j < 8)
	{
		resol[line + (coord[j] - coord[0])][col + (coord[j + 1] - coord[1])] =
			tab[coord[j]][coord[j + 1]];
		j += 2;
	}
	free(coord);
	coord = NULL;
}

static void		ft_reset(int **resol, int piece_nb)
{
	int		l;
	int		c;

	l = 0;
	while (resol[l][0] != -1)
	{
		c = 0;
		while (resol[0][c] != -1)
		{
			if (resol[l][c] == piece_nb + 1)
				resol[l][c] = 0;
			c++;
		}
		l++;
	}
}

static int		ft_check_place(int **tab, int **resol, int line, int col)
{
	int		*coord;
	int		j;

	coord = ft_get_coord(tab);
	j = 0;
	while (j < 8)
	{
		if (resol[line + (coord[j] - coord[0])][col + (coord[j + 1] -
					coord[1])] != 0 || col + (coord[j + 1] - coord[1]) < 0)
		{
			free(coord);
			coord = NULL;
			return (FALSE);
		}
		j += 2;
	}
	free(coord);
	coord = NULL;
	return (TRUE);
}

int				ft_recursive_resol(int ***tab, int **resol, int piece_nb)
{
	int		i[2];

	if (tab[piece_nb] == NULL)
		return (TRUE);
	i[0] = 0;
	while (resol[i[0]][0] != -1)
	{
		i[1] = 0;
		while (resol[0][i[1]] != -1)
		{
			if (resol[i[0]][i[1]] == 0)
				if (ft_check_place(tab[piece_nb], resol, i[0], i[1]) == TRUE)
				{
					ft_place(tab[piece_nb], resol, i[0], i[1]);
					if (ft_recursive_resol(tab, resol, piece_nb + 1) == TRUE)
						return (TRUE);
					ft_reset(resol, piece_nb);
				}
			i[1]++;
		}
		i[0]++;
	}
	return (FALSE);
}
