/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:58:15 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/19 11:58:18 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_putstr_sp(char *str)
{
	ft_putstr(str);
	ft_putchar(' ');
}

void			color(char *color, char *target)
{
	ft_putchar_fd('\033', 2);
	ft_putstr_fd(color, 2);
	ft_putstr_fd(target, 2);
}

static void		prompt_user(t_env *env)
{
	char *user;

	user = get_data(env, "USER");
	ft_putstr("\n# ");
	if (user)
	{
		color(YELLOW, user);
		color(RESET, "");
		ft_putstr(" in ");
	}
	else
	{
		color(RED, "unknown");
		color(RESET, "");
		ft_putstr(" in ");
	}
}

static void		prompt_path(t_env *env)
{
	char	*tmp;
	char	*home;
	char	*new;

	new = NULL;
	tmp = get_data(env, "PWD");
	home = get_data(env, "HOME");
	if (!tmp)
	{
		color(RED, "");
		ft_putstr("somewhere ");
		color(RESET, "");
	}
	else if (tmp && ft_strncmp(tmp, home, ft_strlen(home)) == 0)
		prompt2(new, tmp, home);
	else
	{
		color(BLUE, "");
		ft_putstr_sp(tmp);
		color(RESET, "");
	}
}

void			prompt(t_env *env)
{
	prompt_user(env);
	prompt_path(env);
	color(BLUE, " \n$> ");
	color(RESET, "");
}
