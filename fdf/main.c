/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:05:23 by qdiaz             #+#    #+#             */
/*   Updated: 2016/06/06 14:58:07 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(e->mlx, e->img.img);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}

void	calc_coord(t_point *coord, int x, int y, int **map)
{
	coord->x = 1 * x - 1 * y;
	coord->y = 100 * x + 100 * y;
	coord->y /= 100;
	coord->y -= map[y][x] * 0.15;
	//coord->y -= map[y][x] * coord->delta;
	coord->x *= 12;
	coord->y *= 8;
	//coord->x += coord->pos_x;
	//coord->y += coord->pos_y;
	coord->x += 300;
	coord->y += 300;
}


int		point_map(t_img *img, char *file)
{
	int	i;
	int	**map;

	i = -1;
	map = get_map(file);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->size_line,
			&img->endian);
	while (map[++i])
		draw_line(img, map, i, -1);
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window (e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_img	img;
	t_env	e;

	if (ac >= 2)
	{
		e.mlx = mlx_init();
		e.height = img.height = 750;
		e.width = img.width = 750;
		img.img = mlx_new_image(e.mlx, e.height, e.width);
		point_map(&img, av[1]);
		e.win = mlx_new_window(e.mlx, e.height, e.width, "42 - FDF");
		e.img = img;
		mlx_put_image_to_window(e.mlx, e.win, img.img, 0, 0);
		mlx_key_hook(e.win, key_hook_manager, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_putstr_fd("usage : ./fdf file1\n", 2);
	return (0);
}
