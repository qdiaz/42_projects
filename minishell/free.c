/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:16:42 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/11 15:16:44 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		free_list(t_env **head)
{
	t_env	*current;
	t_env	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		ft_strdel(&(current->name));
		ft_strdel(&(current->content));
		free(current);
		current = next;
	}
	*head = NULL;
}

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}
