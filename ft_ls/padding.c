/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:50:04 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/10 11:58:26 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h> // test

static void	init_pad(t_pad *pad)
{
	pad->len_usr = 0;
	pad->len_grp = 0;
	pad->len_lnk = 0;
	pad->len_siz = 0;
	pad->len_maj = 0;
	pad->len_min = 0;
	pad->len_majmin = 0;
}
/*
   static void		init_pad(t_pad *pad, t_lst **lst)
   {
   pad->len_usr = ft_strlen((*lst)->user_id);
   pad->len_grp = ft_strlen((*lst)->group_id);
   pad->len_lnk = ft_strlen((*lst)->link);
   pad->len_siz = ft_strlen((*lst)->size);
   pad->len_maj = ft_strlen((*lst)->maj);
   pad->len_min = ft_strlen((*lst)->min);
   pad->len_majmin = 0;
   }
   */
static char	*put_s_before(char *str, int max)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

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

static void	apply_padding(t_pad *pad, t_lst *lst)
{
	t_lst *tmp;

	tmp = lst;
	if (tmp->next)
	{
		while (tmp)
		{
			tmp->link = put_s_before(tmp->link, pad->len_lnk);
			tmp->user_id = ft_strnjoin(tmp->user_id, " ", (pad->len_usr - ft_strlen(tmp->user_id)));
			tmp->group_id = ft_strnjoin(tmp->group_id, " ", (pad->len_grp - ft_strlen(tmp->group_id)));
			tmp->size = put_s_before(tmp->size, pad->len_siz);
			tmp->maj = put_s_before(tmp->maj, pad->len_maj);
			tmp->min = put_s_before(tmp->min, pad->len_min);
			tmp->majmin = ft_strjoin(tmp->maj, " ");
			tmp->majmin = ft_strjoin(tmp->majmin, tmp->min);
			tmp = tmp->next;
		}
	}
}

void		padding(t_lst *lst)
{
	t_lst	*tmp;
	t_pad	pad;

	tmp = lst;
	init_pad(&pad);
	while (tmp->next)
	{
		if (pad.len_usr < ft_strlen(tmp->next->user_id))
			pad.len_usr = ft_strlen(tmp->next->user_id);
		if (pad.len_grp < ft_strlen(tmp->next->group_id))
			pad.len_grp = ft_strlen(tmp->next->group_id);
		if (pad.len_lnk < ft_strlen(tmp->next->link))
			pad.len_lnk = ft_strlen(tmp->next->link);
		if (pad.len_siz < ft_strlen(tmp->next->size))
			pad.len_siz = ft_strlen(tmp->next->size);
		if (pad.len_maj < ft_strlen(tmp->next->maj))
			pad.len_maj = ft_strlen(tmp->next->maj);
		if (pad.len_min < ft_strlen(tmp->next->min))
			pad.len_min = ft_strlen(tmp->next->min);
		tmp = tmp->next;
	}
	pad.len_majmin = pad.len_maj + pad.len_min;
	apply_padding(&pad, lst);
}
