/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:53:11 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/17 11:53:47 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cmd(char **cmd, char *cmdp, char **env)
{
	char	*tmp;
	pid_t	father;

	father = fork();
	if (father > 0)
		wait(0);
	else if (father == 0)
	{
		signal(SIGINT, SIG_DFL);
		tmp = ft_strjoin(cmdp, "/");
		ft_strdel(&cmdp);
		cmdp = ft_strjoin(tmp, cmd[0]);
		ft_strdel(&tmp);
		execve(cmdp, cmd, env);
	}
	else
		ft_putendl("cannot fork");
}
