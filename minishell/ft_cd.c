/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:58:23 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/24 16:58:25 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_cd_error(char *name)
{
	ft_putstr_fd("Error:", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("Not such directory", 2);
	ft_putchar('\n');
}

void			ft_cd(char *moveto, t_env *env)
{
	if (!moveto || (ft_strcmp(moveto, "~") == 0))
	{
		while (env)
		{
			if (ft_strcmp(env->name, "HOME") == 0)
			{
				change_varcontent(env, "OLDPWD", getwd(NULL));
				chdir(env->content);
				change_varcontent(env, "PWD", getwd(NULL));
			}
			env = env->next;
		}
	}
	else if (opendir(moveto) == NULL)
	{
		ft_cd_error(moveto);
		return ;
	}
	else
	{
		change_varcontent(env, "OLDPWD", getwd(NULL));
		chdir(moveto);
		change_varcontent(env, "PWD", getwd(NULL));
	}
}
