/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:33:35 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/12 15:47:41 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	**sort_time(int start, int end, char **name, int *time[])
{
	int		i;

	i = start - 1;
	if (end - start > 1)
	{
		while (start < end - 1 && time[0][start + 1])
		{
			if (time[0][start] < time[0][start + 1])
			{
				swap_string(time, name, start, 0);
				start = i;
			}
			else if (time[0][start] == time[0][start + 1])
			{
				if (time[1][start] < time[1][start + 1])
				{
					swap_string(time, name, start, 1);
					start = i;
				}
			}
			start++;
		}
	}
	return (name);
}

static int	while_is_error(char **tab, char **cpy_name, int *cpy_date[])
{
	int i;

	i = 0;
	if (is_what(tab[i]) == -1)
		while (tab[i] && is_what(tab[i]) == -1)
		{
			cpy_name[i] = ft_strdup(tab[i]);
			cpy_date[0][i] = 0;
			cpy_date[1][i] = 0;
			i++;
		}
	return (i);
}

static int	while_is_file(char **tab, char **cpy_name, int *cpy_date[], int i)
{
	int				end;
	int				start;
	struct stat		st;

	start = i;
	if (is_what(tab[i]) == 0)
		while (is_what(tab[i]) == 0)
		{
			stat(tab[i], &st);
			cpy_name[i] = ft_strdup(tab[i]);
			cpy_date[0][i] = (int)st.st_mtime;
			cpy_date[1][i] = (int)st.N_TIME;
			i++;
		}
	end = i;
	cpy_name[i] = NULL;
	cpy_name = sort_time(start, end, cpy_name, cpy_date);
	return (i);
}

static int	while_is_dir(char **tab, char **name, int *date[], int i)
{
	struct dirent	*ret;
	struct stat		st;
	int				start;
	DIR				*dir;

	start = i;
	if (is_what(tab[i]) == 1)
		while (is_what(tab[i]) == 1)
		{
			dir = opendir(tab[i]);
			ret = readdir(dir);
			stat(tab[i], &st);
			name[i] = ft_strdup(tab[i]);
			date[0][i] = (int)st.st_mtime;
			date[1][i] = (int)st.N_TIME;
			closedir(dir);
			i++;
		}
	name[i] = NULL;
	name = sort_time(start, i, name, date);
	return (i);
}

char		**sort_tab_time(char **tab, int len)
{
	int		i;
	char	**cpy_name;
	int		*cpy_date[2];

	i = 0;
	if (!(cpy_name = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	cpy_date[0] = (int *)malloc(sizeof(int) * (len + 1));
	cpy_date[1] = (int *)malloc(sizeof(int) * (len + 1));
	i = while_is_error(tab, cpy_name, cpy_date);
	i = while_is_file(tab, cpy_name, cpy_date, i);
	i = while_is_dir(tab, cpy_name, cpy_date, i);
	return (cpy_name);
}
