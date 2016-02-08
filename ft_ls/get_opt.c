/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:54:29 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/02 11:54:32 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_opt(t_opt *opt)
{
	opt->l = 0;
	opt->R = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
}

static void	print_opt(t_opt *opt) // test
{
	ft_putendl("--- OPT SAVED ---\n");
	printf("l is -> %d\n", opt->l);
	printf("R is -> %d\n", opt->R);
	printf("a is -> %d\n", opt->a);
	printf("r is -> %d\n", opt->r);
	printf("t is -> %d\n\n", opt->t);
}

static void	err_opt(char *err)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putendl_fd(err, 2);
	ft_putstr_fd("usage: ft_ls [-Ralrt] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

static int 	valid_opt(char c)
{
	return ((c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't'));
}

int			get_opt(char *str, t_opt *opt)
{
	int i;

	i = 1;
	init_opt(opt);
	while (str[i] && valid_opt(str[i]))
	{
		if (str[i] == 'l')
			opt->l = 1;
		if (str[i] == 'R')
			opt->R = 1;
		if (str[i] == 'a')
			opt->a = 1;
		if (str[i] == 'r')
			opt->r = 1;
		if (str[i] == 't')
			opt->t = 1;
		i++;
	}
	if (str[i])
		err_opt(&str[i]);
	print_opt(opt);
	return (0);
}
