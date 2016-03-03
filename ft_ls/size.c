/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:50:17 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/03 13:34:00 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*add_unit(int size)
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
	tmp = ft_strnew(toput + 6);
	ft_strncpy(tmp, s, toput);
	ft_strncat(tmp, ".", 1);
	if (s[toput] && s[toput + 1])
	{
		tmp[toput + 1] = s[toput];
		tmp[toput + 2] = s[toput + 1];
		tmp[toput + 3] = '\0';
	}
	return (tmp);
}

char	*format_size(char *s) // pb -l /usr
{
	size_t	size;
	char	*formated;
	char	*end;

	size = ft_strlen(s);
	if (size == 1 && ft_atoi(s) == 0)
		return (ft_strdup("0 B"));
	formated = ft_strnew(size + 1);
	end = ft_strdup(add_unit(size));
	//end = ft_strnew(3);
	//end = add_unit(size);
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
		// if (lst->next) -----> enlever cette condition dans manage opt avant puttotal
		// {
		while (lst) // && lst->perm[0] != 'l' ----> pour les linked file dans /dev par exemple, stdin, stdout, qui ne sont pas cense afficher maj et minor
		{
			if (ft_strncmp(lst->name, ".", 1) != 0)
				res += lst->blok;
			lst = lst->next;
		}
		// }
	}
	ft_putstr("total ");
	ft_putnbr_endl(res);
}
