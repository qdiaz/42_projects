/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:16:09 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/01/12 15:48:32 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_fill_tab(int *line, char *s, int cnt)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (s[i] == '#')
			line[i] = cnt + 1;
		else
			line[i] = 0;
		i++;
	}
	line[i] = -1;
}

static int	**ft_split_in_tab(char *s, int nb)
{
	int i;
	int j;
	int **tetri;

	i = 0;
	j = 0;
	if (!(tetri = (int **)malloc(sizeof(int *) * 4)))
		return (FALSE);
	while (j < 4)
	{
		if (!(tetri[j] = (int *)malloc(sizeof(int) * 5)))
			return (FALSE);
		ft_fill_tab(tetri[j], &s[i], nb);
		i += 5;
		j++;
	}
	return (tetri);
}

int			***ft_split_tetri(char *s)
{
	int i;
	int nb_tetri;
	int ***tetri_tab;

	i = 0;
	nb_tetri = ft_count_tetri(s);
	if (!(tetri_tab = (int ***)malloc(sizeof(int **) * (nb_tetri + 1))))
		return (FALSE);
	while (i < nb_tetri)
	{
		tetri_tab[i] = ft_split_in_tab(s + 21 * i, i);
		i++;
	}
	tetri_tab[i] = NULL;
	free(s);
	s = NULL;
	return (tetri_tab);
}
