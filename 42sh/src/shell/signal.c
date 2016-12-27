/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:55:11 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/17 12:57:45 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

void	sigtstp(int id)
{
	char	cp[2];
	t_shell	*sh;

	(void)id;
	sh = NULL;
	sh = stock_struct(sh, 1);
	cp[0] = sh->term.c_cc[VSUSP];
	cp[1] = 0;
	sh->term.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	tcsetattr(0, 0, &(sh->term));
	ioctl(0, TIOCSTI, cp);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_int);
}

void	sigcont(int id)
{
	t_shell	*sh;

	(void)id;
	sh = NULL;
	sh = stock_struct(sh, 1);
	init_term(sh);
	tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	get_prompt(sh->env);
	color(RED, "$> ");
	color(RESET, "");
	signal(SIGTSTP, ign_signal);
}

void	sigint(int id)
{
	t_shell			*sh;
	t_prompt		*prompt;
	struct winsize	win;

	(void)id;
	sh = NULL;
	prompt = NULL;
	sh = stock_struct(sh, 1);
	prompt = stock_prompt(prompt, 1);
	if (prompt->win_size == 0)
	{
		tputs(tgetstr("up", NULL), 1, ft_putchar_int);
		ioctl(0, TIOCGWINSZ, &win);
		prompt->win_size = win.ws_col;
	}
	prompt_print(prompt, 0);
	ft_strclr(prompt->cmd);
	prompt->i = 0;
	ft_putchar('\n');
	get_prompt(sh->env);
	prompt_print(prompt, 1);
}

void	ign_signal(int id)
{
	(void)id;
	signal(SIGWINCH, win_size);
	signal(SIGCONT, sigcont);
	signal(SIGTSTP, sigtstp);
	signal(SIGINT, sigint);
	signal(SIGSEGV, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
}
