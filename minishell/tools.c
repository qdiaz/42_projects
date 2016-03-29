/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:59:18 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/24 17:37:20 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			count_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

char		**ft_tabdup(char **tab)
{
	char	**tab_cpy;
	int		i;

	i = 0;
	if (!(tab_cpy = (char **)malloc(sizeof(char *) * (count_tablen(tab) + 1))))
		exit(1);
	while (tab[i] != 0)
	{
		tab_cpy[i] = ft_strdup(tab[i]);
		i++;
	}
	tab_cpy[i] = 0;
	return (tab_cpy);
}

void		print_list(t_env *env)
{
	if (env)
	{
		while (env)
		{
			ft_putstr(env->name);
			ft_putchar('=');
			ft_putstr(env->content);
			ft_putchar('\n');
			env = env->next;
		}
	}
	else
		ft_putstr("empty env\n");
}

void		print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

void		print_prompt(char **env)
{
	char	*pwd;

	pwd = get_env_data(env, "PWD=");
	ft_putstr(pwd);
	ft_putchar(' ');
	ft_putstr("$> ");
}
