/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:18:53 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/11 17:18:10 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				main(int argc, char **argv, char **environ)
{
	int		i;
	char	**envi;
	t_env	*env;
	char	*line;

	i = -1;
	line = ft_strdup("");
	envi = ft_tabdup(environ);
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		exit(1);
	env = NULL;
	while (envi[++i] != 0)
		env = env_in_list(envi[i], env);
	free_tab(envi);
	i = 0;
	if (argc == 1 && argv[0])
	{
		while ((read_entry(ft_strsplit(line, ';'), &env)) != -1)
		{
			print_prompt();
			ft_strdel(&line);
			get_next_line(0, &line);
		}
	}
	free_list(&env);
	return (0);
}
