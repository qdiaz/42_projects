/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:36:52 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/16 15:23:05 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	get_new_stdio(t_process *process)
{
	if (process->stdio[0] != 0)
		dup2(process->stdio[0], 0);
	if (process->stdio[1] != 1)
		dup2(process->stdio[1], 1);
	if (process->stdio[2] != 2)
		dup2(process->stdio[2], 2);
	if (process->closefd != -1)
		close(process->closefd);
}

void		launch_builtin(t_shell *sh, t_parse *parse, t_job *job)
{
	int		save_stdio[3];

	save_stdio[0] = dup(0);
	save_stdio[1] = dup(1);
	save_stdio[2] = dup(2);
	get_new_stdio(job->process);
	if ((sh->return_val = do_builtins(sh, job, parse)) == 0)
		job->process->completed = 1;
	dup2(save_stdio[0], 0);
	dup2(save_stdio[1], 1);
	dup2(save_stdio[2], 2);
}

void		launch_bin(t_parse *parse, t_job *job)
{
	get_new_stdio(job->process);
	if (execve(parse->right_path, parse->argv, parse->env) < 0)
	{
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(parse->argv[0], 2);
		exit(127);
	}
}

void		exec_env(t_shell *sh, char *arg, char **env_cpy)
{
	t_parse		*parse;
	t_job		*job;

	parse = init_parse(sh, arg);
	job = NULL;
	if (check_builtins(parse->argv[0]))
		do_builtins(sh, job, parse);
	else if ((parse->pid = fork()) == 0)
	{
		if (execve(parse->right_path, parse->argv, env_cpy) < 0)
		{
			ft_putstr_fd("42sh: command not found: ", 2);
			ft_putendl_fd(parse->argv[0], 2);
			exit(127);
		}
	}
	wait(0);
	free_parse(&parse);
}
