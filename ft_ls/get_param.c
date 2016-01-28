/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:30:05 by qdiaz             #+#    #+#             */
/*   Updated: 2016/01/28 15:30:41 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fill_lst(t_lst *lst, struct stat st)
{

}

void	get_param(char *path) // need opt
{
	DIR 		*dir;
	t_lst		*lst;
	struct dirent 	*ret;

	if (!(dir = opendir(path)) = NULL)
	{
		ft_putendl("error opendir");
		exit(EXIT_FAILURE);
	}
	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
	{
		ft_putendl("error malloc lst");
		exit(EXIT_FAILURE);
	}
	lst = NULL;
	while (ret = readdir(dir))
	{
		lst = fill_lst(file->d_name, )
	}
}
