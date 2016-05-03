/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:53:42 by qdiaz             #+#    #+#             */
/*   Updated: 2016/05/03 18:16:27 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_print_enter(t_term *termi)
{
	int		i;

	i = 0;
	while (termi->ret_tab[i])
	{
		ft_putstr(termi->ret_tab[i]);
		if (termi->ret_tab[i + 1])
			ft_putchar(32);
		i++;
	}
}

int				ft_init_termios(t_term *termi)
{
	struct winsize win;

	termi->enter = 0;
	if (tgetent(NULL, getenv("TERM")) < 1)
		return (0);
	if (tcgetattr(0, &(termi->term)) == -1)
		return (0);
	termi->term.c_lflag &= ~(ICANON | ECHO);
	termi->term.c_cc[VMIN] = 1;
	termi->term.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	termi->nb_col = win.ws_col;
	termi->nb_row = win.ws_row;
	if (tcsetattr(0, 0, &(termi->term)) == -1)
		return (0);
	tputs(tgetstr("vi", NULL), 1, ft_myputchar);
	return (1);
}

int				ft_end_termios(t_term *termi)
{
	termi->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(termi->term)) == -1)
		return (0);
	tputs(tgetstr("te", NULL), 1, ft_myputchar);
	tputs(tgetstr("ve", NULL), 1, ft_myputchar);
	if (termi->enter)
		ft_print_enter(termi);
	return (1);
}
