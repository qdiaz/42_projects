/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:35:35 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/20 19:48:43 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_do_select(char **argv, t_term *termi)
{
	screen_clear();
	arg_to_list(argv, termi);
	count_col(termi);
	return (0);
}

int				main(int argc, char **argv)
{
	t_term		termi;

	(void)argc;
	termi.dblist = NULL;
	//ft_signal();
	if (!ft_init_termios(&termi))
		return (-1);
	if (argc >= 2)
		ft_do_select(argv, &termi);
	if (!ft_end_termios(&termi))
		return (-1);
	return (0);
}
