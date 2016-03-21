/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:57:32 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/21 17:56:33 by qdiaz            ###   ########.fr       */
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

typedef struct		s_env
{
	char			*name;
	char			*data;
	struct s_env	*next;
}					t_env;

/*
 * ============================= get_var_info.c ==============================
*/

char				*get_var_content(char *envar);
char				*get_var_name(char *envar);

/*
 * ================================= param.c =================================
*/

t_env				*env_in_list(char *envar, t_env *start);
int					read_entry(char **cmd, t_env *env);
int					manage_entry(char **cmd, t_env *env);

/*
 * ================================== env.c ==================================
*/

t_env				*ft_set_env(char **cmd, t_env *env);
void				ft_unset_env(t_env **begin_list, char *varname);

/*
* ================================== tools.c ================================
*/

void				prompt(void);
void				print_env(t_env *env);

#endif
