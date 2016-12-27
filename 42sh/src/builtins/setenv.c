/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:39:25 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/11 18:55:00 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void	add_var_env(t_env *env, char **arg)
{
	char	*str;
	char	*tmp;

	free(env->line);
	str = ft_strjoin(*arg, "=");
	tmp = NULL;
	if (arg[1])
	{
		tmp = ft_strjoin(str, arg[1]);
		env->line = ft_strdup(tmp);
		free(tmp);
	}
	else
		env->line = ft_strdup(str);
	free(str);
}

static int	cmp_list_arg(t_env *env, char **arg)
{
	t_env	*tmp;

	tmp = env;
	while (env)
	{
		if (ft_strcmp(env->name, *arg) == 0 && env->flag == 0)
		{
			add_var_env(env, arg);
			env = tmp;
			return (1);
		}
		env = env->next;
	}
	env = tmp;
	return (0);
}

static int	handle_arg_setenv(t_env *env, char **arg)
{
	t_env	*new_elem;
	char	*str;

	if ((arg[0][0] >= 'A' && arg[0][0] <= 'Z') ||
			(arg[0][0] >= 'a' && arg[0][0] <= 'z'))
	{
		if (cmp_list_arg(env, arg) == 0)
		{
			new_elem = (t_env *)malloc(sizeof(t_env));
			new_elem->next = NULL;
			str = ft_strjoin(*arg, "=");
			new_elem->name = ft_strdup(*arg);
			new_elem->flag = 0;
			if (arg[1])
				new_elem->line = ft_strjoin(str, arg[1]);
			else
				new_elem->line = ft_strdup(str);
			free(str);
			push_node(new_elem, &env);
		}
		return (0);
	}
	else
		return (1);
}

int			do_setenv(t_env *env, char **arg)
{
	int		i;

	arg++;
	i = 1;
	while (arg[i])
		i++;
	if (i > 2)
	{
		ft_putendl_fd("setenv: Too many arguments", 2);
		return (1);
	}
	if (!*arg)
		print_env(env);
	else if (print_alpha_error(arg) == 1)
		return (1);
	else if (handle_arg_setenv(env, arg) == 1)
	{
		ft_putendl_fd("setenv: Variable name must begin with a letter.", 2);
		return (1);
	}
	return (0);
}
