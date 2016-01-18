/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:19:48 by qdiaz             #+#    #+#             */
/*   Updated: 2016/01/14 16:02:39 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		cnt_file_in_dir(DIR *dir)
{
	int cnt;
	struct dirent *rd = NULL;

	while ((rd = readdir(dir)) != NULL)
		if (ft_strcmp(rd->d_name, ".") != 0 && ft_strcmp(rd->d_name, "..") != 0)
		{
			ft_putstr(rd->d_name);
			ft_putchar('\n');
			cnt++;
		}
	return (cnt);
}

int		main(int ac, char **av)
{
	int files;
	int i;
	DIR *dir = NULL;
	char *path;

	i = 1;
	if(ac == 1)
	{
		path = "./";
		dir = opendir(path);
		files = cnt_file_in_dir(dir);
	}
	else
	{
		while (av[i])
		{
			ft_putstr(av[i]);
			ft_putstr(" :");
			ft_putchar('\n');
			path = av[i];
			dir = opendir(path);
			files = cnt_file_in_dir(dir);
			ft_putchar('\n');
			i++;
		}
	}
	return(0);
}
