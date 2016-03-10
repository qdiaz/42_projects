/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:49:42 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/10 17:01:38 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void recursive(char *path, t_lst *lst, t_opt *opt, int nb_dir)
{
	char			**dirs;
	int				i;
	int				j;

	i = 0;
	if (!(dirs = (char **)malloc(sizeof(char *) * nb_dir + 1)))
		exit(1);
	while (lst)
	{
		if (lst->is_dir == 1)
		{
			if (opt->a == 0 && lst->name[0] != '.')
			{
				dirs[i] = ft_strdup(lst->name);
				i++;
			}
			else if (opt->a != 0)
			{
				dirs[i] = ft_strdup(lst->name);
				i++;	
			}
		}
		lst = lst->next;
	}
	dirs[i] = NULL;
	// trier tableau par ordre en fn des options
	if (opt->r == 0)
	{
		i = -1;
		while (++i < nb_dir) // si pas opt->r
		{
			if (dirs[i])
			{
				ft_putchar('\n');
				ft_putstr(ft_strjoin(path, dirs[i]));
				ft_putstr(":\n");
				get_param(ft_strjoin(path, add_slash(dirs[i])), opt);
			}
		}
	}
	else if (opt->r == 1)
	{
		j = nb_dir;
		while (j > -1)
		{
			if (dirs[j])
			{
				ft_putchar('\n');
				ft_putstr(ft_strjoin(path, dirs[j]));
				ft_putstr(":\n");
				get_param(ft_strjoin(path, add_slash(dirs[j])), opt);
			}
			j--;
		}
	}
}

void	manage_opt(t_lst *lst, t_opt *opt, char *path)
{
	int hidd;

	hidd = 0;
	lst = lst_sort_ascii(lst);
	if (!opt || (opt->l == 0 && opt->R == 0 && opt->a == 0 && opt->r == 0 && opt->t == 0))
		display_lst(lst, 0);
	else
	{
		if (opt->a)
			hidd = 1;
		if (opt->t)
			lst = lst_sort_time(lst);
		if (opt->r && opt->l)
		{
			if (lst->next != NULL)
				put_total(lst, hidd);
			display_rllst(lst, hidd);
		}
		else if (opt->r)
			display_rlst(lst, hidd);
		if (opt->l && (!opt->r))
		{
			if (lst->next != NULL)
				put_total(lst, hidd);
			display_llst(lst, hidd);
		}
		else if (lst && opt->a && (!opt->r))
			display_lst(lst, hidd);
		else if (lst && (!opt->a) && (!opt->r))
			display_lst(lst, hidd);
		if (lst && opt->R)
			recursive(path, lst, opt, count_dir(&lst));
	}
}

void	get_param(char *path, t_opt *opt)
{
	DIR 			*dir;
	struct dirent	*ret;
	t_lst 			*lst;
	int				is_file;

	is_file = 0;
	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
		exit(1);
	lst = NULL;
	if (!(dir = opendir(path)))
	{
		lst = manage_av_file(path, lst, dir);
		if (lst == NULL)
		{
			ft_putstr("ft_ls: ");
			perror(path);
			return ;
		}
		is_file = 1;
	}
	else if (is_file == 0)
	{
		path = add_slash(path);
		while ((ret = readdir(dir)))
			lst = get_info(lst, ret->d_name, ft_strjoin(path, ret->d_name));
		closedir(dir);
		//ft_putchar('\n');
	}
	if (opt && opt->l)
		padding(lst);
	manage_opt(lst, opt, path);
}

int		main(int ac, char **av)
{
	int		i;
	int		flag;
	char	*path;
	t_opt	opt;

	i = 1;
	flag = 1;
	path = NULL;
	init_opt(&opt);
	if (ac > 1)
	{
		while (av[i] && av[i][0] == '-')
		{
			get_opt(av[i], &opt);
			flag++;
			i++;
		}
		if (ac > flag)
			av = create_tab(av, &opt, ac, flag);
		i = 0;
		if (ac > 1)
		{
			while (i < ac - flag)
			{
				path = av[i];
				get_param(path, &opt);
				i++;
			}
		}
	}
	if (path == NULL)
		get_param("./", &opt);
	return (0);
}
