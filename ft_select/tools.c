/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:55:38 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/21 17:41:50 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_myputchar(int c)
{
	return (write(2, &c, 1));
}

void		screen_clear(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_myputchar);
}

t_term		*ft_stock(t_term *termi, int i)
{
	t_term *tmp = NULL;

	if (i == 0)
		tmp = termi;
	return (tmp);
}

void		ft_up(t_term *termi)
{
	t_dblist	*tmp;

	tmp = termi->dblist;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	tmp->prev->line = 1;
}

void		ft_down(t_term *termi)
{
	t_dblist	*tmp;

	tmp = termi->dblist;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	tmp->next->line = 1;
}
