/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_job.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:22:00 by cboussau          #+#    #+#             */
/*   Updated: 2016/10/27 19:49:54 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void		push_process(t_process *node, t_process **head)
{
	t_process	*tmp;

	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void		create_process(t_process **process, t_token *token, t_shell *sh)
{
	t_process	*new_elem;

	if (!(new_elem = (t_process *)malloc(sizeof(t_process))))
		return ;
	new_elem->next = NULL;
	new_elem->stdio[0] = sh->stdio[0];
	new_elem->stdio[1] = sh->stdio[1];
	new_elem->stdio[2] = sh->stdio[2];
	new_elem->closefd = sh->closefd;
	new_elem->completed = 0;
	new_elem->cmd = ft_strdup(token->cmd);
	push_process(new_elem, process);
}

void		push_job(t_job *node, t_job **head)
{
	t_job	*tmp;

	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	else
		tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void		create_job(t_job **job, t_process **process, t_token *token)
{
	t_job	*new_job;

	if (!(new_job = (t_job *)malloc(sizeof(t_job))))
		return ;
	new_job->next = NULL;
	new_job->linker = token->token_value;
	new_job->process = *process;
	push_job(new_job, job);
}

t_job		*init_job(void)
{
	t_job	*job;

	if (!(job = (t_job *)malloc(sizeof(t_job))))
		return (NULL);
	job->linker = 0;
	job->next = NULL;
	job->process = NULL;
	return (job);
}
