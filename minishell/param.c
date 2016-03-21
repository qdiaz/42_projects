/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:20:56 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/21 17:56:36 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env			*env_in_list(char *envar, t_env *start)
{
	int		i;
	t_env	*tmp;
	t_env	*voyager;
	
	i = 0;
	tmp = (t_env *)malloc(sizeof(t_env));
	voyager = start;
	tmp->name = get_var_name(envar);
	tmp->data = get_var_content(envar);
	//tmp->next = NULL;
	if (start == NULL)
		return (tmp);
	while (voyager->next)
		voyager = voyager->next;
	voyager->next = tmp;
	return (start);
}

int		manage_entry(char **cmd, t_env *env)
{
	if (cmd == NULL)
		return (1);
	if (ft_strcmp(cmd[0], "exit") == 0)
		return (-1);
	else if (ft_strcmp(cmd[0], "setenv") == 0)
	{
		env = ft_set_env(cmd, env);
		return (0);
	}
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		ft_unset_env(&env, cmd[1]);
	else if (ft_strcmp(cmd[0], "env") == 0)
	{
		print_env(env);
		return (0);
	}
	else if (ft_strcmp(cmd[0], "cd") == 0)
	{
		//ft_cd(cmd[1], env);
		return (0);
	}
	return (0);
}

int				read_entry(char **cmd, t_env *env)
{
	int		i;
	char	**tab;

	i = 0;
	while (cmd[i])
	{
		tab = ft_strsplit(cmd[i], ' ');
		if (manage_entry(tab, env) == -1)
			return (-1);
		i++;
		//free_tab(tab);
	}
	return (0);
}
