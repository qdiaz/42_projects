/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:17:06 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/11 15:17:10 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_cd_prev(t_env *env)
{
	char	buf[512];
	char	*tmp;

	while (env)
	{
		if (ft_strcmp(env->name, "OLDPWD") == 0)
		{
			tmp = env->content;
			if (getwd(buf) != NULL)
				change_varcontent(env, "OLDPWD", getwd(NULL));
			chdir(tmp);
			change_varcontent(env, "PWD", getwd(NULL));
		}
		env = env->next;
	}
}

static void		ft_cd_home(t_env *env)
{
	char	buf[512];

	while (env)
	{
		if (ft_strcmp(env->name, "HOME") == 0)
		{
			if (getwd(buf) != NULL)
				change_varcontent(env, "OLDPWD", getwd(NULL));
			chdir(env->content);
			change_varcontent(env, "PWD", getwd(NULL));
		}
		env = env->next;
	}
}

static void		manage_error(char *moveto, t_env *env)
{
	t_stat	st;

	if (stat(moveto, &st) == -1)
	{
		ft_putstr_fd(moveto, 2);
		ft_putstr_fd(": No such file or directory.\n", 2);
	}
	else if (!(S_ISDIR(st.st_mode)))
	{
		ft_putstr_fd(moveto, 2);
		ft_putstr_fd(": Not a directory.\n", 2);
	}
	else if (access(moveto, X_OK) == -1)
	{
		ft_putstr_fd(moveto, 2);
		ft_putstr_fd(": Permission denied.\n", 2);
	}
	else
	{
		change_varcontent(env, "OLDPWD", getwd(NULL));
		chdir(moveto);
		change_varcontent(env, "PWD", getwd(NULL));
	}
}

void			ft_cd(char *moveto, t_env **env)
{
	if (!moveto || (ft_strcmp(moveto, "~") == 0))
		ft_cd_home(*env);
	else if (ft_strcmp(moveto, "-") == 0)
		ft_cd_prev(*env);
	else
		manage_error(moveto, *env);
}
