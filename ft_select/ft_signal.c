/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:35:20 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/21 19:00:16 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_sig_stop(void)
{
	t_term	*termi;
	char	cp[2];

	termi = NULL;
	termi = ft_stock(termi, 1);
	cp[0] = termi->term.c_cc[VSUSP];
	cp[1] = 0;
	termi->term.c_lflag |= (ICANON | ECHO);
	screen_clear();
	tcsetattr(0, 0, &(termi->term));
	tputs(tgetstr("te", NULL), 1, ft_myputchar);
	tputs(tgetstr("ve", NULL), 1, ft_myputchar);
	ioctl(0, TIOCSTI, cp);
}

static void		ft_sig_cont(void)
{
	t_term *termi;

	termi = NULL;
	termi = ft_stock(termi, 1);
	termi->term.c_lflag &= ~(ICANON | ECHO);
	termi->term.c_cc[VMIN] = 1;
	termi->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(termi->term));
	tputs(tgetstr("ti", NULL), 1, ft_myputchar);
	tputs(tgetstr("vi", NULL), 1, ft_myputchar);
	signal(SIGTSTP, ft_catch_signal);
	ft_resize();
	ft_check_size(termi);
}

static void		ft_interrupt(void)
{
	t_term *termi;

	termi = NULL;
	termi = ft_stock(termi, 1);
	ft_end_termios(termi);
	exit(0);
}

void			ft_catch_signal(int i)
{
	if (i == SIGCONT)
		ft_sig_cont();
	else if (i == SIGTSTP)
		ft_sig_stop();
	else if (i == SIGWINCH)
		ft_resize();
	else
		ft_interrupt();
}

void			ft_signal(t_term *termi)
{
	int i;

	i = 1;
	while (i < 32)
	{
		if (signal(SIGINT, SIG_DFL))
		{
			termi->term.c_lflag &= ~(ICANON | ECHO);
			termi->term.c_cc[VMIN] = 1;
			termi->term.c_cc[VTIME] = 0;
		}
		signal(i, ft_catch_signal);
		i++;
	}
}
