/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:50:31 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/22 13:50:33 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lst	*lst_swap(t_lst *p1, t_lst *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

t_lst	*lst_sort_ascii(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next != NULL && ft_strcmp(lst->name, lst->next->name) > 0)
		lst = lst_swap(lst, lst->next);
	lst->next = lst_sort_ascii(lst->next);
	if (lst->next != NULL && ft_strcmp(lst->name, lst->next->name) > 0)
	{
		lst = lst_swap(lst, lst->next);
		lst->next = lst_sort_ascii(lst->next);
	}
	return (lst);
}

t_lst	*lst_sort_time(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next != NULL && (lst->date_id < lst->next->date_id))
		lst = lst_swap(lst, lst->next);
	lst->next = lst_sort_time(lst->next);
	if (lst->next != NULL && (lst->date_id < lst->next->date_id))
	{
		lst = lst_swap(lst, lst->next);
		lst->next = lst_sort_time(lst->next);
	}
	return (lst);
}
