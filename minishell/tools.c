/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:00:52 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/21 17:56:41 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	ft_putstr("$>");
}

void	print_env(t_env *env)
{
	if (env)
	{
		//ft_putstr("salut\n");
		while (env->next != NULL)
		{
			//ft_putstr(env->name);
			ft_putchar('=');
			//ft_putstr(env->data);
			ft_putchar('\n');
			//env = env->next;
		}
	}
	else
		ft_putendl("Empty env");
}
