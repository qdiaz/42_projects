/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:57:50 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/17 13:45:36 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(char **env)
{
	char	*home;
	char	*user;
	char	buf[100];

	getcwd(buf, 100);
	//home = "nfs/2015/q/qdiaz/my_git/minishell";
	//user = "qdiaz";
	home = get_arg_data(env, "HOME");
	user = get_arg_data(env, "USER");
	if (user)
	{
		ft_putstr(" #");
		ft_putstr(user);
		ft_putstr("   ");
	}
	if (home && ft_strstr(buf, home))
	{
		ft_putchar('~');
		ft_putstr(ft_strstr(buf, home) + ft_strlen(home));
	}
	else
		ft_putstr(buf);
	write(1, " $> ", 4);
}
