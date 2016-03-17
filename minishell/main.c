/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:48:12 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/17 15:22:16 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**parse_path(char **env)
{
	char	*path_str;
	char	**split_path;

	split_path = NULL;
	path_str = get_arg_data(env, "PATH");
	if (path_str)
	{
		split_path = ft_strsplit(path_str, ':');
		ft_strdel(&path_str);
		return (split_path);
	}
	return (NULL);
}

static char		**cmd_manage(char **env, char **cmd, char **path)
{
	if (is_builtin(cmd[0]) > 0)
	{
		env = do_builting(cmd, env);
		return (env);
	}
	else
	{
		manage_exe_cmd(env, cmd, path);
	}
	return (env);
}

static void		manage_stdin(char **env, char **cmd, char **path)
{
	char	*line;

	line = NULL;
	while (1)
	{
		prompt(env);
		if (get_next_line(0, &line) == 1)
		{
			cmd = ft_strsplit(line, ' ');
			//ft_putstr(cmd[0]);
			ft_strdel(&line);
			path = parse_path(env);
		}
		if (ft_tablen(cmd))
		{
			if (!(ft_strcmp(cmd[0], "exit")) && ft_tablen(cmd) == 1)
				break ;
		}
		env = cmd_manage(env, cmd, path);
	}
	ft_putchar('\n');
}

int				main(int ac, char **av, char **env)
{
	char	**env_cpy;
	char	**cmd;
	char	**path_cpy;

	env_cpy = NULL;
	av = NULL;
	cmd = NULL;
	path_cpy = NULL;
	env_cpy = ft_tabdup(env);
	if (ac == 1)
		manage_stdin(env_cpy, cmd, path_cpy);
	else
		return (1);
	return (0);
}
