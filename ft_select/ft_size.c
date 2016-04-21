/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:07:15 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/21 18:08:29 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_check_size(t_term *termi)
{
	if (termi->nb_row - 2 < termi->count[0]
			|| termi->nb_col - 2 < termi->count[1])
	{
		screen_clear();
		ft_putendl_fd("Windows size too small.", 2);
		return (0);
	}
	else
	{
		screen_clear();
		ft_print(termi);
	}
	return (1);
}

void	ft_resize(void)
{
	t_term			*termi;
	struct winsize	win;

	termi = NULL;
	termi = ft_stock(termi, 1);
	screen_clear();
	ioctl(0, TIOCGWINSZ, &win);
	termi->nb_col = win.ws_col;
	termi->nb_row = win.ws_row;
	ft_check_size(termi);
}
