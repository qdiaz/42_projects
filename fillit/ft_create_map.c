/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:37:17 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/01/12 15:45:45 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_define_min_sqr(int nb_tetri)
{
	int	i;

	i = 2;
	while ((i * i) < (nb_tetri))
		i++;
	if (i % 2 != 0)
		i++;
	return (i);
}

int		**ft_create_map(int size)
{
	int	grid[2];
	int	**map;

	grid[0] = 0;
	if (!(map = (int **)malloc(sizeof(int *) * (size + 1))))
		return (FALSE);
	while (grid[0] <= size)
	{
		if (!(map[grid[0]] = malloc(sizeof(int) * (size + 1))))
			return (FALSE);
		grid[1] = 0;
		while (grid[1] <= size)
		{
			if (grid[0] == size || grid[1] == size)
				map[grid[0]][grid[1]] = -1;
			else
				map[grid[0]][grid[1]] = 0;
			grid[1]++;
		}
		grid[0]++;
	}
	return (map);
}
