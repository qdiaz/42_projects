/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:54:47 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/02 11:54:50 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h> // printf

static void	display_llst(t_lst *lst)
{
	t_lst *tmp;

	tmp = lst->next;
	while (tmp)
	{
		ft_putstr(tmp->perm);
		ft_putchar(' ');
		ft_putstr(tmp->link);
		ft_putchar(' ');
		//ft_putnbr(lst->blok);
		//ft_putchar(' ');
		ft_putstr(tmp->user_id);
		ft_putchar(' ');
		ft_putstr(tmp->group_id);
		ft_putchar(' ');
		ft_putstr(tmp->size); // a faire
		ft_putchar(' ');
		ft_putstr(tmp->date);
		ft_putchar(' ');
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
	lst->next = NULL;
}

char	*add_slash(char *path)
{
	int i;

	i = ft_strlen(path) - 1;
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoin(path, "/");
	ft_putstr("path | "); // test
	ft_putendl(path); // test
	ft_putchar('\n'); // test
	return (path);
}

static int	count_total(t_lst *lst/*, t_opt *opt*/)
{
	int res;

	res = 0;
	/*if (opt->l == 1)
	  {*/
	while /*(lst != NULL)*/ (lst)
	{
		//if (lst->name[0] != '.')
		res += lst->blok;
		lst = lst->next;
	}
	/*}*/
	return (res);
}

//static void	free_content(t_lst *tmp)
//{
//
//}

void	free_lst(t_lst *head)
{
	t_lst *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		//free_content(tmp);
		free(tmp);
	}
}

static void get_perm(struct stat *st, t_lst *lst)
{
	ft_bzero(lst->perm, 11);
	lst->perm[0] = (S_ISDIR(st->st_mode)) ? 'd' : '-';
	lst->perm[1] = (st->st_mode & S_IRUSR) ? 'r' : '-';
	lst->perm[2] = (st->st_mode & S_IWUSR) ? 'w' : '-';
	lst->perm[3] = (st->st_mode & S_IXUSR) ? 'x' : '-';
	lst->perm[4] = (st->st_mode & S_IRGRP) ? 'r' : '-';
	lst->perm[5] = (st->st_mode & S_IWGRP) ? 'w' : '-';
	lst->perm[6] = (st->st_mode & S_IXGRP) ? 'x' : '-';
	lst->perm[7] = (st->st_mode & S_IROTH) ? 'r' : '-';
	lst->perm[8] = (st->st_mode & S_IWOTH) ? 'w' : '-';
	lst->perm[9] = (st->st_mode & S_IXOTH) ? 'x' : '-';
}

static void	fill_info(struct stat st, t_lst *lst, char *path, char *file)
{
	struct passwd	*pwd;
	struct group	*grp;

	if ((pwd = getpwuid(st.st_uid)))
		lst->user_id = ft_strdup(pwd->pw_name);
	if ((grp = getgrgid(st.st_gid)))
		lst->group_id = ft_strdup(grp->gr_name);
	lst->chem = /*ft_strdup(*/path/*)*/;
	lst->name = /*ft_strdup(*/file/*)*/;
	lst->date = ft_strsub(ctime(&st.st_mtime), 4, 12);
	lst->link = ft_itoa(st.st_nlink);
	lst->size = ft_itoa(st.st_size);
	lst->blok = st.st_blocks;
	get_perm(&st, lst);
}

t_lst	*get_info(t_lst *start, char *file, char *path)
{
	struct stat	st;
	t_lst	*tmp;
	t_lst	*ptr;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	tmp->next = NULL;
	ptr = start;
	if (stat(path, &st) == 1)
	{	
		ft_putendl("fail to get stats");
		exit(EXIT_FAILURE);
	}
	if (lstat(path, &st) <= 0)
	{
		fill_info(st, tmp, path, file);
	}
	if (start == NULL)
		return (tmp);
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
	return (tmp);
}

void	get_param(char *path)
{
	int				total;
	DIR 			*dir;
	struct dirent	*ret;
	t_lst 			*lst;
	t_lst			*start;

	if (!(dir = opendir(path)))
	{
		ft_putendl("error opening file");
		exit(EXIT_FAILURE);
	}
	//ret = readdir(dir);
	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
	{
		ft_putendl("error malloc lst");
		exit(EXIT_FAILURE);
	}
	start = lst;
	lst = NULL; // lst->next = NULL; sinon premier maillon de la liste = NULL;
	while (/*ret*/(ret = readdir(dir))) // ou while ((ret = readdir(dir)))
	{
		lst = get_info(lst, ret->d_name, ft_strjoin(path, ret->d_name));
	lst = start;
	}
	total = count_total(lst);
	ft_putstr("total | ");
	ft_putnbr(total);
	ft_putstr("\n\n");
	
	padding(lst);
	display_llst(lst);
	
	// count blocks en parcourant la liste
	closedir(dir);
	//free_lst(lst);
}

int		main(int ac, char **av)
{
	int i;
	t_opt opt;

	if (ac > 1)
	{
		i = 1;
		if (av[i][0] == '-' && av[i][1])
		{
			get_opt(av[i], &opt);
			i = 2;
		}
		while (av[i])
		{
			get_param(add_slash(av[i])); // add opt
			i++;
		}
	}
	else
	{
		ft_putendl("\n--- AC = 0 ---\n");
		get_param("./");
	}
	return (0);
}
