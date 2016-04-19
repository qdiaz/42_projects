/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:58:35 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/19 11:58:37 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env		*env_cpy(t_env *envtmp, t_env *env)
{
	while (env)
	{
		envtmp = var_cpy(env, envtmp);
		env = env->next;
	}
	return (envtmp);
}

t_env		*var_cpy(t_env *start, t_env *cpy)
{
	t_env	*tmp;
	t_env	*voyager;

	tmp = (t_env *)malloc(sizeof(t_env));
	voyager = cpy;
	tmp->name = ft_strdup(start->name);
	tmp->content = ft_strdup(start->content);
	tmp->next = NULL;
	if (voyager == NULL)
		return (tmp);
	while (voyager->next)
		voyager = voyager->next;
	voyager->next = tmp;
	return (cpy);
}

char		*getvarcontent(char *envar)
{
	int		i;
	int		j;
	char	*varcontent;

	i = 0;
	j = 0;
	while (envar[i])
		i++;
	while (envar[j] != '=' && envar[j])
		j++;
	j += 1;
	if (j == i)
		return (NULL);
	else
		varcontent = ft_strsub(envar, j, i);
	return (varcontent);
}

char		*getvarname(char *envar)
{
	int		i;
	int		j;
	char	*varname;

	i = 0;
	j = 0;
	while (envar[i] != '=' && envar[i])
		i++;
	varname = ft_strsub(envar, j, i);
	return (varname);
}

void		change_varcontent(t_env *env, char *name_ref, char *data)
{
	while (env)
	{
		if (!(ft_strcmp(env->name, name_ref)))
		{
			if (env->content)
				ft_strdel(&(env->content));
			env->content = ft_strdup(data);
		}
		env = env->next;
	}
}
