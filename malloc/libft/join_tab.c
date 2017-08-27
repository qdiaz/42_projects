/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 20:39:03 by qdiaz             #+#    #+#             */
/*   Updated: 2017/08/27 20:39:13 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*join_tab(char **arg)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp2 = ft_strdup(arg[0]);
	i = 1;
	while (arg[i])
	{
		tmp = ft_strjoin(tmp2, " ");
		free(tmp2);
		tmp2 = ft_strjoin(tmp, arg[i]);
		free(tmp);
		i++;
	}
	return (tmp2);
}
