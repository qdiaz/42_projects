/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:48:12 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/21 15:31:55 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	int		i;
	char	**envi;
	t_env	*environ;
	char	*line;

	i = 0;
	line = ft_strdup("");
	envi = ft_tabdup(env);
	while (!(environ = (t_env *)malloc(sizeof(t_env))))
		exit(1);
	env = NULL;
	while (envi[++i] != 0)
		environ = env_in_list(envi[i], environ);
	//free_tab(envi);
	if (ac == 1)
	{
		ft_strlen(av[0]);
		while ((read_entry(ft_strsplit(line, ';'), environ)) != -1)
		{
			prompt();
			get_next_line(0, &line);
		}
	}
	//free_list(&env);
	return (0);
}
