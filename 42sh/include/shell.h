/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:47:18 by qdiaz             #+#    #+#             */
/*   Updated: 2016/11/11 18:41:59 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/dir.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <libft.h>
# include <funct.h>

# define RED "[31m"
# define PURPLE "[1;35m"
# define GREEN "[32m"
# define CYAN "[0;36m"
# define BLUE "[1;34m"
# define RESET "[39m"

typedef struct		s_env
{
	char			*line;
	char			*name;
	int				flag;
	struct s_env	*next;
}					t_env;

typedef struct		s_hist
{
	char			*str;
	struct s_hist	*prev;
	struct s_hist	*next;
}					t_hist;

typedef struct		s_shell
{
	int				stdio[3];
	int				closefd;
	int				return_val;
	struct s_hist	*head;
	struct s_hist	*hist;
	struct s_env	*env;
	struct termios	term;
}					t_shell;

t_env				*init_env(char **env);
t_env				*delete_elem(t_env *env);
t_shell				*stock_struct(t_shell *sh, int i);
t_shell				*init_struct(char **env);
t_hist				*create_hist(void);
t_hist				*init_hist(char *str);
void				deal_with_file(t_shell *sh);
void				heredoc(t_shell *sh, char *code);
void				init_stdio(t_shell *sh);
void				exec_env(t_shell *sh, char *arg, char **env_cpy);
void				push_node(t_env *env, t_env **head);
void				push_hist(t_hist **head, t_hist *new_node);
void				add_history(t_shell *sh);
void				get_prompt(t_env *env);
void				free_env(t_env *env);
void				free_hist(t_hist *hist);
void				free_shell(t_shell *sh);
void				exec_cmd(t_shell *sh);
void				print_env(t_env *env);
void				restore_env(t_env *node, char **save);
void				exec_pipe(t_shell *sh);
void				export_new_variable(t_env *env, char *arg);
void				add_to_list(t_env *env, char *arg, int flag);
void				exec_cmd_lst(t_shell *sh, char **cmd, char *line);
void				change_varcontent(t_env *env, char *name_ref, char *data);
void				ign_signal(int id);
void				change_directory(t_env *env, char *cmd);
int					deal_with_opt(t_shell *sh, char **arg, char **env_cpy);
int					do_designator(t_shell *sh, char **cmd);
int					do_export(t_env *env, char **arg);
int					do_cd(t_env *node, char **arg);
int					do_setenv(t_env *env, char **arg);
int					do_unsetenv(t_env *env, char **arg, int flag);
int					arg_in_dir(t_env *env, char *arg);
int					get_index(t_env *env);
int					get_index(t_env *env);
int					do_history(t_shell *sh, char **cmd);
int					do_option(t_shell *sh, char **cmd, int fd);
int					option_d(t_shell *sh, char **cmd, int fd);
int					option_r(t_shell *sh, int fd);
int					open_history(void);
int					get_intel(t_env *env, char *str);
int					check_env(t_env *env);
int					reset_term(t_shell *sh);
int					reset_term_no_free(t_shell *sh);
int					init_term(t_shell *sh);
int					deal_with_env(t_shell *sh, char **arg);
int					create_new_variable(t_env *env, char **arg);
int					check_local_variable(t_env *env, char *arg, int flag);
char				*get_home(t_env *env);
char				*join_env(char **arg);
char				**get_env(t_env *env);
char				*deal_with_termcap(t_shell *sh);
char				*termcap_heredoc(t_shell *shell);

#endif
