/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:32:28 by qdiaz             #+#    #+#             */
/*   Updated: 2016/04/20 19:48:50 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include "libft/libft.h"
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <sys/ioctl.h>

typedef struct		s_dblist
{
	char			*value;
	int				select;
	int				line;
	struct s_dblist	*next;
	struct s_dblist	*prev;
	int				len;
}					t_dblist;

typedef enum		e_enum
{
	LEFT_KEY = 4479771,
	RIGHT_KEY = 4414235,
	UP_KEY = 4283163,
	DOWN_KEY = 4348699,
	ESC_KEY = 27,
	SPACE_KEY = 32,
	DEL_KEY = 127,
	RET_KEY = 10,
	SUP_KEY = 2117294875,
	HOME_KEY = 4741915,
	END_KEY = 4610843,
	PAGE_UP_KEY = 2117425947,
	PAGE_DOWN_KEY = 2117491483,
	TAB_KEY = 9,
	CRTL_A_KEY = 1
}					t_enum;

typedef struct		s_term
{					
	struct termios	term;
	char			*name_term;
	int				nb_col;
	int				nb_row;
	int				enter;
	int				count[2];
	char			**ret_tab;
	t_dblist		*dblist;
}					t_term;

int					ft_myputchar(int c);
int					ft_init_termios(t_term *all);
int					ft_end_termios(t_term *all);
void				screen_clear(void);
t_dblist			*lst_init(void);
t_dblist			*fill_list(char *str);
void				add_link(term *termi, t_dblist *list);
void				arg_to_list(char **argv, t_term *termi);
void				count_col(t_term *termi);

#endif
