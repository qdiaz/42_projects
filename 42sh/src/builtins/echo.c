/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 14:55:27 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/15 13:35:42 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		print_echo(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if ((size_t)i < ft_strlen(cmd))
			ft_putchar(cmd[i]);
		i++;
	}
}

int				do_echo(char **cmd)
{
	int i;
	int cnt;

	i = 1;
	cnt = 0;
	if (!cmd[1])
		ft_putchar('\n');
	else
	{
		if (cmd[1] && ft_strcmp(cmd[1], "-n") != 0)
			cnt = 1;
		else
			i++;
		while (cmd[i])
		{
			print_echo(cmd[i]);
			if (cmd[i + 1])
				ft_putchar(' ');
			i++;
		}
		if (cnt == 1)
			ft_putchar('\n');
	}
	return (0);
}
