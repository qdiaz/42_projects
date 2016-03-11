/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:11:48 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/11 17:43:42 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		free_data(t_lst **lst)
{
	if ((*lst)->link)
		ft_strdel(&(*lst)->link);
	if ((*lst)->user_id)
		ft_strdel(&(*lst)->user_id);
	if ((*lst)->group_id)
		ft_strdel(&(*lst)->group_id);
	if ((*lst)->min)
		ft_strdel(&(*lst)->min);
	if ((*lst)->maj)
		ft_strdel(&(*lst)->maj);
	if ((*lst)->size)
		ft_strdel(&(*lst)->size);
	else
		ft_strdel(&(*lst)->majmin);
	if ((*lst)->name)
		ft_strdel(&(*lst)->name);
	if ((*lst)->date)
		ft_strdel(&(*lst)->date);
}

void			free_lst(t_lst **lst)
{
	while (*lst)
	{
		free_data(lst);
		*lst = (*lst)->next;
	}
	free((*lst));
	lst = NULL;
}
