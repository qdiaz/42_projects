/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 16:36:31 by cboussau          #+#    #+#             */
/*   Updated: 2016/11/17 12:41:54 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcaps.h>

static void	reset_prompt(t_prompt *prompt)
{
	size_t	i;
	size_t	j;

	j = 3;
	i = 0;
	tputs(tgetstr("vi", NULL), 1, ft_putchar_int);
	tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
	while (i < ft_strlen(prompt->cmd))
	{
		if (j >= prompt->win_size)
		{
			tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
			tputs(tgetstr("up", NULL), 1, ft_putchar_int);
			j = 0;
		}
		j++;
		i++;
	}
	tputs(tgetstr("cd", NULL), 1, ft_putchar_int);
	color(RED, "$> ");
	color(RESET, "");
}

static void	print_cursor(t_prompt *prompt, int show_cursor, int i)
{
	if (i == prompt->i && show_cursor == 1)
	{
		tputs(tgetstr("mr", NULL), 1, ft_putchar_int);
		ft_putchar(' ');
	}
	tputs(tgetstr("me", NULL), 1, ft_putchar_int);
}

void		prompt_print(t_prompt *prompt, int show_cursor)
{
	int		i;
	size_t	j;

	i = 0;
	reset_prompt(prompt);
	j = 3;
	while (prompt->cmd[i])
	{
		tputs(tgetstr("me", NULL), 1, ft_putchar_int);
		if (i == prompt->i && show_cursor == 1)
			tputs(tgetstr("mr", NULL), 1, ft_putchar_int);
		if (prompt->copy_mode == 1 && i >= prompt->cursor_start &&
				i <= prompt->cursor_end)
			tputs(tgetstr("mr", NULL), 1, ft_putchar_int);
		ft_putchar(prompt->cmd[i]);
		j++;
		if (j >= prompt->win_size)
		{
			ft_putendl("");
			tputs(tgetstr("cr", NULL), 1, ft_putchar_int);
			j = 0;
		}
		i++;
	}
	print_cursor(prompt, show_cursor, i);
}

void		prompt_shell(t_shell *sh, t_prompt *prompt, char *buff)
{
	if (prompt->i < 4500)
	{
		deal_with_charac(prompt, buff);
		deal_with_space(prompt, buff);
	}
	go_down_line(prompt, buff);
	go_up_line(prompt, buff);
	deal_with_backspace(prompt, buff);
	deal_with_delete(prompt, buff);
	deal_with_left(prompt, buff);
	deal_with_right(prompt, buff);
	deal_with_up(sh, prompt, buff);
	deal_with_down(sh, prompt, buff);
	go_to_start_of_line(prompt, buff);
	go_to_previous_word(prompt, buff);
	go_to_next_word(prompt, buff);
	go_to_end(prompt, buff);
	start_copy_mode(prompt, buff);
	copy_string(prompt, buff);
	cut_string(prompt, buff);
	paste_string(prompt, buff);
	start_auto_complete(prompt, buff);
	input_clear(sh, prompt, buff);
}

char		*deal_with_termcap(t_shell *sh)
{
	t_prompt	*prompt;
	int			ret;
	char		buff[4];
	char		*str;

	prompt = init_prompt();
	stock_prompt(prompt, 0);
	prompt_print(prompt, 1);
	str = NULL;
	while ((ret = read(0, buff, BUFF_SIZE) != -1))
	{
		prompt_shell(sh, prompt, buff);
		if (buff[0] == 4 && !prompt->cmd[0])
			exit_eof(sh, prompt);
		if (buff[0] == 10)
		{
			str = input_return(sh, prompt);
			break ;
		}
		ft_bzero(buff, 4);
	}
	free_prompt(&prompt);
	return (str);
}
