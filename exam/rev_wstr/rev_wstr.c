/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:14:04 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/23 09:19:12 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_word(char *s, int cnt)
{
	while (s[cnt] && s[cnt] != ' ' && s[cnt] != '\t')
	{
		ft_putchar(s[cnt]);
		cnt++;
	}
}

void	rev_wstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			print_word(s, i + 1);
			ft_putchar(' ');
		}
		if (i == 0)
			print_word(s, i);
		i--;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	ft_putchar('\n');
	return (0);
}
