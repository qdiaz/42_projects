/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:55:38 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/20 19:48:50 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_myputchar(int c)
{
	return (write(2, &c, 1));
}

void	screen_clear(void)
{
	sleep(1);
	ft_putendl("test");
	sleep(1);
	tputs(tgetstr("cl", NULL), 1, ft_myputchar);
}

void	ft_count_col(t_term *termi)
{
	t_dblist	*tmp;

	termi->count[0] = termi->dblist->len;
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (tmp->len > termi->count[0])
			termi->count[0] = tmp->len;
		tmp = tmp->next;
	}
}
