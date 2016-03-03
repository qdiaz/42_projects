/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:22:19 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/24 16:44:44 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return(0);
}

int		count_words(char *str)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (is_separator(str[i + 1]) == 1 &&
				is_separator(str[i]) == 0)
			words++;
		i++;
	}
	return (words);
}

void	write_word(char *word, char *str)
{
	int		i;

	i = 0;
	while (is_separator(str[i]) == 0)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
}

void	write_tab(char **tab, char *str)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (is_separator(str[i]) == 0)
		{
			j = 0;
			while (is_separator(str[i + j]) == 0)
				j++;
			tab[word] = (char*)malloc(sizeof(char) * (j + 1));
			write_word((tab[word]), (str + i));
			i += j;
			word++;
		}
		else
			i++;
	}
	tab[word] = NULL;
}

char	**ft_split(char *str)
{
	char**tab;
	int	count;
	count = count_words(str);
	tab = (char**)malloc(sizeof(char*) * (count + 1));
	write_tab(tab, str);
	return (tab);
}

int		main(int ac, char **av)
{
	char    **tab;
	int     i;
	int     j;

	i = 0;
	if (ac == 2)
	{
		tab = ft_split(av[1]);
		while (tab[i])
		{
			j = 0;
			while (tab[i][j])
			{
				write(1, &tab[i][j], 1);
				j++;
			}
			write(1, " ", 1);
			write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
