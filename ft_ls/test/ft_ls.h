/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:34:25 by qdiaz             #+#    #+#             */
/*   Updated: 2016/01/28 15:34:27 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./libft/libft.h"

# include <unistd.h> // write, readlink
# include <dirent.h> // opendir, readdir, closedir
# include <sys/stat.h> // stat, lstat
# include <pwd.h> // getpwuid
# include <uuid/uuid.h> // getpwuid, getgrgid
# include <grp.h> // getgrgid
# include <sys/xattr.h> // listxattr, getxattr
# include <time.h> // time, ctime
# include <stdlib.h> // malloc, free, exit
# include <stdio.h> // perror, strerror

typedef struct 		s_opt
{
	int				l;
	int 			R;
	int 			a;
	int 			r;
	int 			t;
	char			error;
}					t_opt;

typedef struct		s_info
{
	mode_t			mode;
	uid_t			uid;
	gid_t			gid;
}					t_info;

typedef struct		s_lst
{
	char			*name;
	//char 			*path;
	struct s_lst 	*next;
}					t_lst;

#endif