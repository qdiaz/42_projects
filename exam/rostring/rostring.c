/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:17:32 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/24 16:21:52 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int        ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void    rostring(char *str)
{
	char	*new;
	int		first, first_end;
	int		word;
	int		i;

	new = malloc(ft_strlen(str));

	i = 0;
	word = -1;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			first = i;
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				++i;
			first_end = i;
			break ;
		}
		i++;
	}
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (word != -1)
				write(1, " ", 1);
			word = i;
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				++i;
			write(1, &str[word], i - word);
			continue ;
		}
		++i;
	}
	if (word != -1)
		write(1, " ", 1);
	write(1, &str[first], first_end - first);
}



int        main(int c, char **v)
{
	if (c > 1)
		rostring(v[1]);
	write(1, "\n", 1);
	return (0);
}
