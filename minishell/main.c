/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:57:51 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/21 18:21:13 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		no_more_lines(char *line, t_env *env)
{
	while (read_entry(ft_strsplit(line, ';'), &env) != -1)
	{
		prompt(env);
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	ft_strdel(&line);
}

int				main(int argc, char **argv, char **environ)
{
	int		i;
	char	**envi;
	t_env	*env;
	char	*line;

	i = -1;
	line = ft_strdup("");
	envi = ft_tabdup(environ);
	signal(SIGINT, SIG_IGN);
	env = NULL;
	while (envi[++i] != 0)
		env = env_in_list(envi[i], env);
	free_tab(envi);
	if (argc == 1 && argv[0])
		no_more_lines(line, env);
	free_list(&env);
	return (0);
}
