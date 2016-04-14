/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:13:49 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/14 17:13:51 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# define RED "[31m"
# define BLUE "[34m"
# define CYAN "[36m"
# define RESET "[39m"
# define GREEN "[32m"
# define YELLOW "[33m"
# define MAGENTA "[35m"

typedef struct			s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}						t_env;

typedef struct stat		t_stat;

char					*get_data(t_env *env, char *ref_name);
char					*ft_getbin_path(char *cmd);
char					*ft_getbin_name(char *cmd);
void					ft_env_error(char *file);
void					ft_env_usage(char opt);
void					ft_bad_opt(char c);
void					ft_env_i(t_env *env, char **cmd);
int						env_manage_error(char *cmd);
int						exe_fork2(t_env *env, char **cmd, char **path_tab);
char					**part_tabcpy(char **tab);
char					**ft_tabdup_path(char **tab, char *content);
char					**ft_strsplit_ws(char const *s);
void					already_exist(t_env **begin_list, char *varname);
int						list_size(t_env *env);
char					**list_in_tab(t_env *env);
char					**path_in_tab(t_env *env, char **cmd);
int						exe_fork(t_env *env, char **cmd, char **path_tab);
void					ft_env(t_env **env, t_env *tmpenv, char **cmd);
t_env					*var_cpy(t_env *env, t_env *cpy);
t_env					*env_cpy(t_env *envtmp, t_env *env);
void					change_varcontent(t_env *env,
										char *name_ref, char *data);
void					ft_cd(char *moveto, t_env **env);
char					*getvarname(char *envar);
char					*getvarcontent(char *envar);
void					ft_unsetenv(t_env **begin_list, char *varname);
t_env					*ft_setenv(char **cmd, t_env **env);
void					free_list(t_env **head);
void					free_tab(char **tab);
char					**ft_tabdup(char **tab);
int						count_tablen(char **tab);
t_env					*env_in_list(char *envar, t_env *start);
void					print_list(t_env *env);
void					print_tab(char **tab);
int						read_entry(char **cmd, t_env **env);
void					prompt(t_env *env);
#endif
