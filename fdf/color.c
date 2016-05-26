/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:03:08 by qdiaz             #+#    #+#             */
/*   Updated: 2016/05/26 14:03:33 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		choose_color(int **map, int y, int x, int choose)
{
	if (choose == 1)
	{
		if ((map[y - 1][x] > 0 && map[y][x] > 0) || (map[y - 1][x] > 0 &&
					map[y][x] <= 0))
			return (0x1E7FCB);
		else
			return (0xF0E36B);
	}
	else
	{
		if ((map[y][x] > 0 && map[y][x + 1] > 0) || ((map[y][x] <= 0
						&& map[y][x + 1] > 0) || (map[y][x] > 0
							&& map[y][x + 1] <= 0)))
			return (0x1E7FCB);
		else
			return (0xF0E36B);
	}
}
