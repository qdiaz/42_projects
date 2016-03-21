/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:22:19 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/21 15:27:08 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_setenv_error(void)
{
	ft_putstr_fd("Error: Usage: setenv [varname] [Content]\n", 2);
}

static t_env	*add_var(t_env *start, char *name, char *data)
{
	t_env	*tmp;
	t_env	*voyager;

	tmp = (t_env *)malloc(sizeof(t_env));
	voyager = start;
	tmp->name = ft_strdup(name);
	tmp->data = ft_strdup(data);
	tmp->next = NULL;
	if (start == NULL)
		return (tmp);
	while (voyager->next)
		voyager = voyager->next;
	voyager->next = tmp;
	return (start);
}

t_env			*ft_set_env(char **cmd, t_env *env)
{
	if (!(cmd[1]) || !(cmd[2]))
	{
		ft_setenv_error();
		return (NULL);
	}
	env = add_var(env, cmd[1], cmd[2]);
	return (env);
}

void			ft_unset_env(t_env **begin_list, char *varname)
{
	t_env	*tmp;

	tmp = *begin_list;
	if (*begin_list)
	{
		if (!(ft_strcmp((*(begin_list))->name, varname)))
		{
			tmp = *begin_list;
			*begin_list = (*(begin_list))->next;
			ft_strdel(&(tmp->name));
			ft_strdel(&(tmp->data));
			free(tmp);
			ft_unset_env(begin_list, varname);
		}
		else
			ft_unset_env(&(*begin_list)->next, varname);
	}
}
