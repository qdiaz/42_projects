/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:06:51 by qdiaz             #+#    #+#             */
/*   Updated: 2016/06/06 14:59:05 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_stop(int x, int y, int **map, int *stop)
{
	if (y > 0 && *stop == 0 && map[y - 1][x] == -2000000000)
		*stop = 1;
}

int		ft_abs(int a, int b)
{
	int	c;

	c = a - b;
	if (c < 0)
		c *= -1;
	return (c);
}

void	init_parse(void)
{
	t_point	pt;

	pt.pos_x = 0;
	pt.pos_y = 0;
	pt.delta = 1;
}
