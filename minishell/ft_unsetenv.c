/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:58:53 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/24 16:58:54 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		unsetenv_error(char *varname)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(varname, 2);
	ft_putstr_fd(": Not found\n", 2);
}

void			ft_unsetenv(t_env **begin_list, char *varname)
{
	t_env	*tmp;

	tmp = *begin_list;
	if (*begin_list)
	{
		if (!(ft_strcmp((*(begin_list))->name, varname)))
		{
			tmp = *begin_list;
			*begin_list = (*(begin_list))->next;
			ft_strdel(&(tmp->name));
			ft_strdel(&(tmp->content));
			free(tmp);
		}
		else
			ft_unsetenv(&(*begin_list)->next, varname);
	}
	else if (*begin_list == NULL)
		unsetenv_error(varname);
}
