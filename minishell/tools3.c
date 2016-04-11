/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:20:40 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/11 17:17:44 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_tabdup_path(char **tab, char *content)
{
	char	**tab_cpy;
	int		i;

	i = 0;
	if (!(tab_cpy = (char **)malloc(sizeof(char *) * (count_tablen(tab) + 2))))
		exit(1);
	while (tab[i] != 0)
	{
		tab_cpy[i] = ft_strdup(tab[i]);
		i++;
	}
	tab_cpy[i] = ft_strdup(content);
	free_tab(tab);
	return (tab_cpy);
}

char	**part_tabcpy(char **tab)
{
	int		i;
	int		j;
	int		count;
	char	**new;

	i = 2;
	j = 0;
	count = 0;
	while (tab[i] != 0)
	{
		count++;
		i++;
	}
	if (!(new = (char **)malloc(sizeof(char *) * count + 1)))
		return (NULL);
	i = 2;
	while (tab[i] != 0)
	{
		new[j] = ft_strdup(tab[i]);
		j++;
		i++;
	}
	new[j] = NULL;
	return (new);
}

int		list_size(t_env *env)
{
	int		size;

	size = 0;
	while (env)
	{
		size++;
		env = env->next;
	}
	return (size);
}

char	**list_in_tab(t_env *env)
{
	int		size;
	char	*str;
	char	*tmp;
	char	**envir;
	int		i;

	i = 0;
	size = list_size(env);
	if (!(envir = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (env)
	{
		tmp = ft_strjoin(env->name, "=");
		str = ft_strjoin(tmp, env->content);
		ft_strdel(&tmp);
		envir[i] = str;
		i++;
		env = env->next;
	}
	envir[i] = 0;
	return (envir);
}

char	*get_var_content(char **env, char *var)
{
	int		i;
	int		start;
	char	*tmp;
	char	*content;

	if (env && *env)
	{
		i = 0;
		while (env[i])
		{
			if (!ft_strncmp(env[i], var, ft_strlen(var)))
			{
				start = ft_strlen(var);
				tmp = ft_strsub(env[i], start, ft_strlen(env[i]) - start);
				content = ft_strdup(tmp);
				ft_strdel(&tmp);
				return (content);
			}
			i++;
		}
		return (NULL);
	}
	return (NULL);
}
