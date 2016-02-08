/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:55:15 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/02 11:55:17 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*modif_str(char *str, int max)
{
	int i;
	int j;
	int k;
	char *tmp;

	i = 0;
	j = max - (int)ft_strlen(str);
	if (!(tmp = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	if (j > 0)
	{
		while (i < max)
		{
			while (i < j)
				tmp[i++] = ' ';
			k = 0;
			while (i < max)
				tmp[i++] = str[k++];
			i++;
		}
		return (tmp);
	}
	else
		return (str);
}

void	apply_padding(int len_usr, int len_grp, int len_lnk, int len_siz, t_lst *lst) // faire struct pour passer a la norme
{
	t_lst *tmp;

	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->link = modif_str(tmp->link, len_lnk);
		tmp->user_id = modif_str(tmp->user_id, len_usr);
		tmp->group_id = modif_str(tmp->group_id, len_grp);
		tmp->size = modif_str(tmp->size, len_siz);
	}
	tmp->next = NULL;
}

void	padding(t_lst *lst)
{
	t_lst	*tmp;
	int		len_grp;
	int		len_usr;
	int		len_lnk;
	int		len_siz;

	tmp = lst;
	len_usr = 0;
	len_grp = 0;
	len_lnk = 0;
	len_siz = 0;
	while (tmp->next)
	{
		if (len_usr < (int)ft_strlen(tmp->next->user_id))
			len_usr = (int)ft_strlen(tmp->next->user_id);
		if (len_grp < (int)ft_strlen(tmp->next->group_id))
			len_grp = (int)ft_strlen(tmp->next->group_id);
		if (len_lnk < (int)ft_strlen(tmp->next->link))
			len_lnk = (int)ft_strlen(tmp->next->link);
		if (len_siz < (int)ft_strlen(tmp->next->size))
			len_siz = (int)ft_strlen(tmp->next->size);
		tmp = tmp->next;
	}
	apply_padding(len_usr, len_grp, len_lnk, len_siz, lst);
}
