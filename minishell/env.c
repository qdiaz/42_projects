/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:00:26 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/17 13:46:58 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_arg_data(char **env, char *str)
{
	int		i;
	int		start;
	char	*tmp;
	char	*content;

	if (env && *env)
	{
		i = 0;
		while (env[i])
		{
			if (!ft_strncmp(env[i], str, ft_strlen(str)))
			{
				start = ft_strlen(str) + 1;
				tmp = ft_strsub(env[i], start, ft_strlen(*env) - start);
				content = ft_strdup(tmp);
				ft_strdel(&tmp);
				return (content);
			}
			i++;
		}
	}
	return (NULL);
}

