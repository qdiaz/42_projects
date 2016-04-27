/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:57:04 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/27 18:55:21 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_under_line(char *str)
{
	tputs(tgetstr("us", NULL), 1, ft_myputchar);
	ft_putstr_fd("\033[32m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("ue", NULL), 1, ft_myputchar);
}

static void		ft_print_select(char *str)
{
	tputs(tgetstr("so", NULL), 1, ft_myputchar);
	ft_putstr_fd("\033[1;31m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("se", NULL), 1, ft_myputchar);
}

static void		ft_underline(char *str)
{
	tputs(tgetstr("us", NULL), 1, ft_myputchar);
	tputs(tgetstr("so", NULL), 1, ft_myputchar);
	ft_putstr_fd("\033[1;36m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("se", NULL), 1, ft_myputchar);
	tputs(tgetstr("ue", NULL), 1, ft_myputchar);
}

static void		ft_behaviour(t_dblist *list)
{
	if (list->line == 1 && list->select == 1)
		ft_underline(list->value);
	else if (list->line == 1)
		ft_under_line(list->value);
	else if (list->select == 1)
		ft_print_select(list->value);
	else
		ft_putendl_fd(list->value, 2);
}

void			ft_print(t_term *termi)
{
	int			nb_col;
	int			nb_files_in_col;
	int			i;
	int			j;
	t_dblist	*tmp;

	i = 1;
	j = 0;
	nb_col = termi->nb_col / (max_size(termi) + 2);
	//ft_putnbr(nb_col);
	nb_files_in_col = (list_size(termi) + 1) / (nb_col);
	//ft_putnbr(nb_files_in_col);
	tmp = NULL;
	ft_behaviour(termi->dblist);
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (!(i % (nb_files_in_col + 1)))
		{
			tputs(tgetstr("rc", NULL), 1, ft_myputchar);
			while (j++ <= (max_size(termi)) * i)
				tputs(tgetstr("nd", NULL), 1, ft_myputchar);
		}
		else
		{
			tputs(tgetstr("cr", NULL), 1, ft_myputchar);
			while (j++ <= (max_size(termi)) * (i - 1))
				tputs(tgetstr("nd", NULL), 1, ft_myputchar);
		}
		j = 0;
		ft_behaviour(tmp);
		tmp = tmp->next;
		i++;
	}
}
