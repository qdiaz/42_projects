/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:57:32 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/17 12:08:22 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <dirent.h>

char		*get_arg_data(char **env, char *var);

void			prompt(char **env);

void	execute_cmd(char **cmd, char *cmdp, char **env);

#endif
