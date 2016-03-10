/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:50:17 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/10 17:00:31 by qdiaz            ###   ########.fr       */
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
	else if (size >= 10 && size <= 12)
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
	ft_strcat(tmp, ".");
	if (s[toput] && s[toput + 1] && s[toput + 2])
	{
		tmp[toput + 1] = s[toput];
		tmp[toput + 2] = s[toput + 1];
		tmp[toput + 3] = '\0';
	}
	return (tmp);
}

char	*format_size(char *s)
{
	size_t	size;
	char	*formated;
	char	*end;

	size = ft_strlen(s);
	if (size == 1 && ft_atoi(s) == 0)
		return (ft_strdup("0 B"));
	formated = ft_strnew(size);
	end = ft_strdup(add_unit(size));
	if (size >= 4)
	{
		formated = add_dot(s, size);
		free(s);
		s = NULL;
		ft_strcat(formated, end);
		free(end);
		end = NULL;
		return (formated);
	}
	else
		return (ft_strjoin(s, end));
	ft_strjoin(formated, s);
	ft_strjoin(formated, end);
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

int		count_dir(t_lst **lst, t_opt *opt)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = *lst;
	if (opt->a == 1)
	{
	while (tmp)
	{
		if (tmp->is_dir)
			i++;
		tmp = tmp->next;
	}
	return (i);
	}
	else if (opt->a == 0)
	{
		while (tmp)
		{
			if (tmp->is_dir &&ft_strncmp(&tmp->name[0], ".", 1))
				i++;
			tmp = tmp->next;
		}
		return (i);
	}
	return (0);
}
