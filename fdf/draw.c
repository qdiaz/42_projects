/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:03:55 by qdiaz             #+#    #+#             */
/*   Updated: 2016/05/26 14:37:31 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_tall_line(t_img *img, t_point *p1, t_point *p2, int color)
{
	t_point	point;
	int		count;

	point.x = p1->x;
	count = point.x - p2->x;
	if (color == 0xF036B)
		color = 0x1E7FCB;
	while (point.x <= p2->x)
	{
		point.y = p1->y + (p2->y - p1->y) * (point.x - p1->x)
			/ (p2->x - p1->x);
		draw_pixel(img, point.x, point.y, color);
		point.x++;
	}
}

void	ft_draw_large_line(t_img *img, t_point *p1, t_point *p2, int color)
{
	t_point	point;
	int		count;

	point.y = p1->y;
	count = point.y - p2->y;
	if (color == 0xF036B)
		color = 0xE1E7FCB;
	while (point.y >= p2->y)
	{
		point.x = p1->x + (p2->x - p1->x) * (point.y - p1->y)
			/ (p2->y - p1->y);
		draw_pixel(img, point.x, point.y, color);
		point.y--;
	}
}

void	draw_line(t_img *img, int **map, int y, int x)
{
	t_point	coord;
	t_point	coord_next;
	t_point	coord_tall;
	int		stop;

	stop = coord.x = coord.y = 0;
	while (map[y][++x + 1] != -2000000000)
	{
		calc_coord(&coord, x, y, map);
		calc_coord(&coord_next, (x + 1), y, map);
		calc_stop(x, y, map, &stop);
		if (y > 0 && stop == 0)
		{
			calc_coord(&coord_tall, x, y - 1, map);
			ft_draw_line(img, &coord_tall, &coord, choose_color(map, y, x, 1));
		}
		ft_draw_line(img, &coord, &coord_next, choose_color(map, y, x, 0));
	}
	calc_stop(x, y, map, &stop);
	if (y > 0 && stop == 0 && x > 0)
	{
		calc_coord(&coord, x, y, map);
		calc_coord(&coord_tall, x, y - 1, map);
		ft_draw_line(img, &coord_tall, &coord, choose_color(map, y, x, 1));
	}
}

void	ft_draw_line(t_img *img, t_point *p1, t_point *p2, int color)
{
	if (ft_abs(p2->x, p1->x) >= ft_abs(p2->y, p1->y))
	{
		if (p1->x == p2->x)
			draw_pixel(img, p1->x, p1->y, color);
		else if (p1->x < p2->x)
			ft_draw_tall_line(img, p1, p2, color);
		else
			ft_draw_tall_line(img, p2, p1, color);
	}
	else
	{
		if (p1->x == p2->y)
			draw_pixel(img, p1->x, p1->y, color);
		if (p1->y > p2->y)
			ft_draw_large_line(img, p1, p2, color);
		else
			ft_draw_large_line(img, p2, p1, color);
	}
}

void	draw_pixel(t_img *img, int width, int heigth, int color)
{
	char	*pixel;

	if ((heigth < 750 && width < 750) && (heigth >= 0 && width >= 0))
	{
		pixel = img->data + heigth * img->size_line + (img->bpp / 8) * width;
		pixel[2] = (char)(color >> 16);
		pixel[1] = (char)(color >> 8);
		pixel[0] = (char)(color);
	}
}
