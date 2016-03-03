/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:09:31 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/02 13:58:28 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	expand_str(char *s)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t')
		j--;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] && i <= j)
	{
		while ((s[i] == ' ' || s[i] == '\t') 
				&& (s[i + 1] == ' ' || s[i + 1] == '\t'))
			i++;
		if (s[i] == ' ' || s[i] == '\t')
			ft_putstr("   ");
		else
			ft_putchar(s[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac ==2)
		expand_str(av[1]);
	ft_putchar('\n');
	return (0);
}
