/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:55:57 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/16 12:55:59 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*add_unit(char *s, int size)
{
	if (size >= 1 && size <= 3)
		return (" B");
	else if (size >= 4 && size <= 6)
		return (" K");
	else if (size >= 7 && size <= 9)
		return (" M");
	else if (size >= 10 && size <= 13)
		return (" G");
	else
		return (" T");
}

static char	*add_dot(char *s, size_t size)
{
	size_t	toput;
	char	*tmp;

	toput = size % 3;
	((toput == 0)) ? toput = 3 : toput;
	tmp = ft_strnew(size + 1);
	ft_strncpy(tmp, s, toput);
	ft_strncat(tmp, ".", 1);
	if (s[toput] && s[toput + 1])
	{
		tmp[toput + 1] = s[toput];
		tmp[toput + 2] = s[toput + 1];
	}
	return (tmp);
}

char	*format_size(char *s) // pb -l /usr
{
	size_t	size;
	char	*formated;
	char	*end;

	size = ft_strlen(s);
	formated = ft_strnew(size + 1);
	end = ft_strnew(2);
	end = add_unit(formated, size);
	if (size >= 4)
	{
		formated = add_dot(s, size);
		ft_strcat(formated, end);
		return (formated);
	}
	ft_strcpy(formated, s);
	ft_strcat(formated, end);
	ft_strjoin(formated, "\0");
	return (formated);
}

void	put_total(t_lst *lst, int hidd)
{
	int res;

	res = 0;
	if (hidd)
	{
		while (lst)
		{
			res += lst->blok;
			lst = lst->next;
		}
	}
	else
	{
		while (lst)
		{
			if (ft_strncmp(lst->name, ".", 1) != 0)
				res += lst->blok;
			lst = lst->next;
		}
	}
	ft_putstr("total ");
	ft_putnbr_endl(res);
}
