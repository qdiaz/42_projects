/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:15:39 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/04 17:15:28 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include <shell.h>
# include <libft.h>

typedef struct		s_lst
{
	char			*name;
	size_t			select;
	char			*save;
	size_t			len;
	size_t			line;
	int				index;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_intel
{
	size_t			length;
	struct s_lst	*tail;
	struct s_lst	*head;
}					t_intel;

typedef struct		s_struct
{
	int				on;
	size_t			size_last;
	size_t			col;
	size_t			row;
	size_t			nb_col;
	size_t			nb_item;
	size_t			coeff;
	size_t			count;
	size_t			realcol;
	size_t			len;
	size_t			delkey;
	size_t			size_w;
	int				fd;
	char			buff[BUFF_SIZE];
	struct termios	term;
	struct s_intel	*node;
}					t_struct;

t_intel				*init_lst(char **argv);
t_intel				*add_intel(t_intel *node, char *argv);
t_struct			*init_select_struct(char **argv);
t_struct			*stock_select_struct(t_struct *info, int i);
char				*deal_with_term(t_struct *info);
char				*do_select(char **argv, int id);
void				push_lst(t_lst *node, t_lst **head);
void				clean_lst(t_struct *info);
void				print_opt(t_lst *ptr, t_struct *info);
void				deal_with_arrow(t_struct *info);
void				deal_with_col(t_struct *info);
void				longest_word(t_struct *info);
void				print_lst(t_struct *info);
void				init_ptr(t_struct *info);
void				del_elem_from_list(t_struct *info);
void				left_arrow(t_struct *info, t_lst *ptr);
void				right_arrow(t_struct *info, t_lst *ptr);
void				check_size(t_struct *info);
void				win_select_size(int id);
void				start_end(t_struct *info);
void				free_lst(t_struct *info);
void				my_tab(t_struct *info, t_lst *ptr);
char				*main_select(int argc, char **argv);
char				*auto_complete(char *cmd);
char				*join_cmd(char **sel);
char				*deal_with_slash(char *cmd);
char				*deal_with_dir(char *cmd);
char				*split_if_dir(char *cmd);
char				*join_if_dir(char *tmp, char *cmd);
char				*first_occur(char **tab_files, char *cmd);
char				*exec_select(char *cmd);
char				*exec_select_cmd(char *frag_cmd, char **tab_files);
char				*exec_select_one_result(char *filenames, char **tab_exec);
char				*exec_select_null(char **tab_files);
char				*join_for_select(char **tab_files, char *cmd);
char				*arg_exists(char *cmd);
char				*arg_does_not_exist(char *cmd);
char				*send_result(char *select_result, char *cmd);
char				*add_index_tab(char **sel);
char				*get_res_arg(char **sel, char *cmd, int i);
int					deal_with_cmd(char *cmd);
int					first_occur_index(char **tab_files, char *cmd);

#endif
