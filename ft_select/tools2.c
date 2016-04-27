/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:17:46 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/27 14:53:07 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_op_display(t_term *termi, int i)
{
	int			nb_files_in_col;
	int			nb_col;
	int			j;
	t_dblist	*tmp;

	tmp = NULL;
	tmp = termi->dblist->next;
	i = 0;
	j = 0;
	nb_col = termi->nb_col / (list_size(termi));
	nb_files_in_col = (list_size(termi)) / nb_col;
	if (list_size(termi) / nb_col < termi->nb_row)
	{
		ft_putnbr(nb_col);
		ft_putnbr(nb_files_in_col);
	}
	else
		ft_putendl_fd("Too small", 2);
}

int			strlenint(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			nb_max_col(t_term *termi, int max)
{
	int		res;

	res = termi->nb_col / (int)max;
	return (res);
}

int			list_size(t_term *termi)
{
	t_dblist	*tmp;
	int			size;

	size = 1;
	tmp = NULL;
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int			max_size(t_term *termi)
{
	t_dblist	*tmp;
	int			max_len;

	tmp = NULL;
	max_len = strlenint(termi->dblist->value);
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (strlenint(tmp->value) > max_len)
			max_len = strlenint(tmp->value);
		tmp = tmp->next;
	}
	return (max_len);
}
