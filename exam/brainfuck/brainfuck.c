/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:12:25 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/22 16:55:46 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*boucle(char *s, int i)
{
	int count;

	count = 0;
	while (1)
	{
		if (*s == '[')
			count++;
		else if (*s == ']')
			count--;
		if (count == 0)
			return (s);
		s += i;
	}
	return (NULL);
}

void	brainfuck(char *s, char *buf)
{
	while (*s)
	{
		if (*s == '>')
			buf++;
		else if (*s == '<')
			buf--;
		else if (*s == '+')
			(*buf)++;
		else if (*s == '-')
			(*buf)--;
		else if (*s == '.')
			write(1, buf, 1);
		else if (*s == '[' && !(*buf))
			s = boucle(s, 1);
		else if (*s == ']' && *buf)
			s = boucle(s, -1);
		s++;
	}
}

int		main(int ac, char **av)
{
	char	buf[2048];
	int		i;

	i = 0;
	if (ac > 1)
	{
		while (i < 2048)
			buf[i++] = 0;
		brainfuck(av[1], buf);
	}
	else
		write(1, "\n", 1);
	return (0);
}
