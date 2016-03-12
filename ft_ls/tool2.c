/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:09:53 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/12 15:47:58 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_link(char *path)
{
	char	buf[1024];
	int		ret;

	ret = readlink(path, buf, 1023);
	if (ret == -1)
		return ;
	buf[ret] = '\0';
	ft_putstr(" -> ");
	ft_putstr(buf);
}

char	*get_pathname(t_lst *lst, char *path)
{
	char*tmp;

	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		lst->path = ft_strjoin(tmp, lst->name);
		ft_strdel(&tmp);
	}
	else
		lst->path = ft_strjoin(path, lst->name);
	return (path);
}

char	*get_path(char *path)
{
	int		i;
	int		j;
	int		end;
	char	*new;

	j = 0;
	path = remove_slash(path);
	i = ft_strlen(path);
	end = i;
	while (i > 0 && path[i - 1] != '/')
		i--;
	new = ft_strnew(end - i + 1);
	while (path[i])
	{
		new[j] = path[i];
		i++;
		j++;
	}
	return (new);
}

void	swap_string(int *time[], char **name, int start, int j)
{
	int		itmp;
	char	*stmp;

	itmp = 0;
	itmp = time[j][start + 1];
	time[j][start] = time[j][start + 1];
	time[j][start + 1] = itmp;
	stmp = name[start];
	name[start] = ft_strdup(name[start + 1]);
	name[start + 1] = ft_strdup(stmp);
}
