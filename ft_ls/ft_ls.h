/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:19:10 by qdiaz             #+#    #+#             */
/*   Updated: 2016/01/14 15:36:06 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <sys/attr.h>
#include <time.h>
#include <stdio.h>

typedef struct		s_option
{
	int				l;
	int				r_big;
	int				a;
	int				r;
	int				t;
}					t_option;

#endif
