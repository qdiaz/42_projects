/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:37:35 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/01/12 15:43:47 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_char(char *str, int *tab)
{
	if (!str[tab[0]])
		ft_error();
	while (str[tab[0]])
	{
		if (str[tab[0]] == '.')
			tab[1]++;
		if (str[tab[0]] == '#')
			tab[2]++;
		if (str[tab[0]] == '\n' && str[tab[0] + 1] != '\n')
			tab[3]++;
		if ((str[tab[0]] == '\n' && str[tab[0] + 1] == '\n')
				|| (str[tab[0]] == '\n' && str[tab[0] + 1] == '\0'))
			tab[4]++;
		tab[0]++;
	}
	if (tab[4] == 0 || tab[1] != (12 * tab[4]) || tab[2] != (4 * tab[4])
			|| tab[3] != (tab[4] * 4))
		ft_error();
	return (TRUE);
}

static int	ft_check_line(char *s)
{
	int cnt;

	while (*s)
	{
		cnt = 0;
		while (*s != '\n')
		{
			s++;
			cnt++;
		}
		if (cnt != 4)
			ft_error();
		else if (*s == '\n' && *(s + 1) == '\n')
			s += 2;
		else
			s++;
	}
	return (TRUE);
}

static int	ft_check_next_diez(char *s, int i, int diez)
{
	if (diez < 4)
	{
		if (s[i + 1] != '#' && s[i + 5] != '#')
		{
			while (s[i - 1] == '#')
			{
				if (s[i + 4] == '#')
					return (TRUE);
				i--;
			}
			return (FALSE);
		}
	}
	return (TRUE);
}

static int	ft_check_shape(char *s, int i, int cnt)
{
	int diez;

	diez = 0;
	while ((size_t)i < ft_strlen(s) + 1)
	{
		if (s[i] == '#')
		{
			diez++;
			if (ft_check_next_diez(s, i, diez) == FALSE)
				ft_error();
		}
		if (s[i] == '\n')
			cnt++;
		if (cnt == 4)
		{
			if (diez != 4)
				ft_error();
			diez = 0;
			cnt = 0;
			i++;
		}
		i++;
	}
	return (TRUE);
}

int			ft_check_file(char *str)
{
	int i;
	int cnt;
	int *tab;

	i = 0;
	cnt = 0;
	if (!(tab = (int *)malloc(sizeof(int) * 5)))
		ft_error();
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	ft_check_char(str, tab);
	ft_check_line(str);
	ft_check_shape(str, i, cnt);
	free(tab);
	tab = NULL;
	return (TRUE);
}
