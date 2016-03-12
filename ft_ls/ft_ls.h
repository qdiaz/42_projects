/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:49:24 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/12 15:51:25 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define N_TIME st_mtimespec.tv_nsec
# include "./libft/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_pad
{
	size_t			len_usr;
	size_t			len_grp;
	size_t			len_lnk;
	size_t			len_siz;
	size_t			len_maj;
	size_t			len_min;
	size_t			len_majmin;
}					t_pad;

typedef struct		s_opt
{
	int				l;
	int				big_r;
	int				a;
	int				r;
	int				t;
}					t_opt;

typedef struct		s_lst
{
	char			*name;
	char			perm[11];
	char			*user_id;
	char			*group_id;
	char			*date;
	int				date_id;
	int				ntime;
	int				blok;
	int				is_dir;
	char			*link;
	char			*size;
	char			*maj;
	char			*min;
	char			*majmin;
	char			*path;
	struct s_lst	*next;
}					t_lst;

void				swap_string(int *time[], char **name, int start, int j);
void				put_link(char *path);
void				free_lst(t_lst **lst);

int					is_what(char *tab);
int					count_dir(t_lst *lst, t_opt *opt);
void				fill_info(struct stat st, t_lst *new,
		char *file, char *path);

char				*add_slash(char *path);
char				*remove_slash(char *path);

void				ft_putnbr_endl(int n);
void				ft_putstr_s(char *s);
void				put_total(t_lst *lst, int hidd);

char				**create_tab(char **av, t_opt *opt, int ac, int flag);
char				**reverse_tab(char **tab);
char				**sort_tab_time(char **tab, int len);

void				get_param(char *path, t_opt *opt);

void				padding(t_lst **lst, t_pad *pad);

char				*format_size(char *s);
char				*join_maj_min(dev_t device_id);

void				display_rllst(t_lst *lst, int hidd);
void				display_llst(t_lst *lst, int hidd);
void				display_rlst(t_lst *lst, int hidd);
void				display_lst(t_lst *lst, int hidd);

int					get_opt(char *str, t_opt *opt);
void				init_opt(t_opt *opt);

t_lst				*lst_sort_ascii(t_lst *lst);
t_lst				*lst_sort_time(t_lst *lst);

t_lst				*manage_av_file(char *path, t_lst *lst, DIR *dir);
t_lst				*get_info(t_lst *head, char *file, char *path);

void				recursive(char *path, t_lst *lst, t_opt *opt);
void				manage_opt(t_lst *lst, t_opt *opt, char *path);

char				*get_path(char *path);
char				*get_pathname(t_lst *lst, char *path);

#endif
