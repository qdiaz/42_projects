/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:17:34 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/21 16:40:45 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*get_var_content(char *envar)
{
	int		i;
	int		j;
	char	*varcontent;

	i = 0;
	j = 0;
	while (envar[i])
		i++;
	while (envar[j] != '=')
		j++;
	j += 1;
	varcontent = ft_strsub(envar, j, i);
	return (varcontent);
}

char			*get_var_name(char *envar)
{
	int		i;
	int		j;
	char	*varname;

	i = 0;
	j = 0;
	while (envar[i] != '=')
		i++;
	varname = ft_strsub(envar, j, i);
	return (varname);
}
