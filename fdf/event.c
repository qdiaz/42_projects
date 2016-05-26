/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:33:05 by qdiaz             #+#    #+#             */
/*   Updated: 2016/05/26 14:51:28 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		do_zoom(int keycode, t_env *env)
{
	if (keycode == 27 || keycode == 78)
		env->img->width -= 1;
	//else if (keycode == 24 || keycode == 69)
	//	env->map.padding += 1;
}

/*static void		do_elevation(int keycode, t_env *env)
{
	if (keycode == 30) // left bracket
		env->z_factor += 1;
	else if (keycode == 33) // right bracket
		env->z_factor -= 1;
}

static void		do_directions(int keycode, t_env *env)
{
	if (keycode == 124)
		env->map.offsetx += 10;
	else if (keycode == 123)
		env->map.offsetx -= 10;
	else if (keycode == 126)
		env->map.offsety -= 10;
	else if (keycode == 125)
		env->map.offsety += 10;
}

static void     do_perspective(int keycode, t_env *env)
{
	if (keycode == 272)
	{
		if (env->pers > 0.3)
			env->pers -= 0.1;
	}
	if (keycode == 257)
	{
		if (env->pers < 0.8)
			env->pers += 0.1;
	}
}*/

int				key_hook_manager(int keycode, t_env *env)
{
	//if (keycode == 53 || keycode == 12)
	//{
	//	free_list(env->list);
	//	exit(0);
	//}
	do_zoom(keycode, env);
	//do_elevation(keycode, env);
	//do_directions(keycode, env);
	//do_perspective(keycode, env);
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env.img, 0, 0);
	return (0);
}
