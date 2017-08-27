/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:33:05 by qdiaz             #+#    #+#             */
/*   Updated: 2016/06/06 14:56:20 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_exit(void)
{
	ft_putendl("exit");
	exit(0);
}

int				key_hook_manager(int keycode, t_env *env)
{
	if (keycode == 53)
		ft_exit();
	else if (keycode == 69)
	{
		ft_putendl("+ pave num");
	}
	else if (keycode == 78)
	{
		ft_putendl("- pave num");
	}
	else if (keycode == 123)
	{
		env->pt.x -= 10;
		ft_putnbr(env->pt.x);
		ft_putendl("fleche gauche");
	}
	else if (keycode == 124)
	{
		env->pt.pos_x += 10;
		ft_putendl("fleche droite");
	}
	else if (keycode == 125)
	{
		env->pt.pos_y -= 10;
		ft_putendl("fleche bas");
	}
	else if (keycode == 126)
	{
		env->pt.pos_y += 10;
		ft_putendl("fleche haut");
	}
	else if (keycode == 116)
	{
		env->pt.delta += 0.2;	
		ft_putendl("page up");
	}
	else if (keycode == 121)
	{
		env->pt.delta -= 0.2;	
		ft_putendl("page down");
	}
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}
