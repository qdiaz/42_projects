/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:30:47 by qdiaz             #+#    #+#             */
/*   Updated: 2016/01/28 15:30:50 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h> // printf

int	main(int ac, char **av)
{
	int i;
	char *path;
	t_opt opt;

	if (ac > 1)
	{
		i = 1;
		if (av[i][0] == '-' && av[i][1])
		{
			if (get_opt(av[i], &opt))
				return (1);
			i = 2;
		}
		while (av[i])
		{
			path = av[i];
			get_param(path);
			i++;
		}
	}
	else
	{
		printf("--- AC = 0 ---\n");
		get_param(".");
	}
	return (0);
}
