/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:49:12 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/22 13:49:14 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h> // test

static char *get_file_name(char *path)
{
	int end;
	int start;
	char *tmp;

	end = ft_strlen(path) - 1;
	start = end;
	while (path[start] != '/' && start > 0)
		start--;
	if (start == 0)
		tmp = ft_strsub(path, start, end + 1);
	else
		tmp = ft_strsub(path, start + 1, end);
	return (tmp);
}

char *format_path(char *path)
{
	int	i;
	char	*tmp;

	if (path)
	{
		i = ft_strlen(path) - 1;
		if (path[i] == '/')
			return (NULL);
		else
		{
			tmp = ft_strdup(path);
			while (tmp[i] != '/' && i > 0)
				i--;
			if (i == 0)
			{
				tmp = ft_strdup("./");
				//free(path);
				return (tmp);
			}
			else
			{
				tmp = add_slash(ft_strndup(path, i));
				//free(path);
				return (tmp);
			}
		}
	}
	else
		return (NULL);
}

t_lst	*manage_av_file(char *path, t_lst *lst, DIR *dir)
{
	char *formated;
	char *file_name;
	struct dirent *ret;

	formated = format_path(path);
	if (formated == NULL)
		return (NULL); // exit ok
	//else
	//	formated = ft_strdup(format_path(path));
	if (!(dir = opendir(formated)))
	{
		ft_putstr("ft_ls: ");
		perror(remove_slash(path));
		exit(1);
	}
	else
	{
		file_name = get_file_name(path);
		while ((ret = readdir(dir)))
		{
			if ((ft_strcmp(ret->d_name, file_name) == 0)) // si match
			{
				lst = get_info(lst, ret->d_name, path);
				break;
			}
		}
		if (!lst)
			return (NULL);
		closedir(dir);
		return (lst);
	}
	return (NULL);
}