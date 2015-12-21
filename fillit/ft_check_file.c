/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:37:35 by adu-pelo          #+#    #+#             */
/*   Updated: 2015/12/18 16:13:32 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> // test

static int	*ft_alloc_int_tab(void)
{
	int *tab;

	if (!(tab = (int *)malloc(sizeof(int) * 5)))
		ft_error();
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	return (tab);
}

static int	ft_check_char(char *str)
{
	int *tab;

	tab = ft_alloc_int_tab();
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
		if (str[tab[0]] == '\n' && str[tab[0] + 1] == '\n')
			tab[4]++;
		tab[0]++;
	}
	if ((tab[1] + tab[2] + tab[3] + tab[4]) != (((tab[4] + 1) * 21) - 1))
	{
		printf("%d = ", tab[1] + tab[2] + tab[3] + tab[4]);
		printf("%d", ((tab[4] + 1) * 21) - 1);
		ft_putstr("check char ko 1"); // test
		ft_error();
	}
	if (tab[4] >= 1)
		tab[4]++;
	if (/*tab[4] == 0 &&*/(tab[1] != (12 * tab[4]) || tab[2] != (4 * tab[4]) || tab[3] != (tab[4] * 4)))
	{
		ft_putstr("check char ko 2"); // test
		ft_error();
	}
	ft_putstr("check char ok"); // test
	return (TRUE);
}

static int	ft_check_line(char *str)
{
	int i;
	int cnt;

	i = 0;
	while (str[i])
	{
		cnt = 0;
		while (str[i] != '\n')
		{
			i++;
			cnt++;
		}
		if (cnt != 4)
		{
			ft_putstr("\n\ncheck line ko"); // test
			ft_error();
		}
		else if (str[i] == '\n' && str[i + 1] == '\n')
			i += 2;
		else
			i++;
	}
	ft_putstr("\n\ncheck line ok\n\n"); // test
	return (TRUE);
}
/*
static int	ft_check_size(char *str) // ko
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		ft_putchar('a');
		if (str[i] == '\n')
		{
			ft_putchar('b');
			cnt++;
		}
		if (cnt == 4 && str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_putchar('c');
			cnt = 0;
			i++;
		}
		if (cnt != 4 && str[i] == '\n' && str[i + 1] != '\n')
		{
			ft_putchar('d');
			ft_putstr("\n\ncheck size ko 1"); // test
			ft_error();
		}
		i++;
	}
	if (str[i] != '\n')
	{
		ft_putchar('e');
		ft_putstr("\n\ncheck size ko 2"); // test
		ft_error();
	}
	ft_putstr("\n\ncheck size ok"); // test
	return (TRUE);
}
*/
int			ft_check_file(char *str)
{
	ft_check_char(str);
	ft_check_line(str);
	// ft_check_size(str);
	ft_putstr("all check ok"); // test
	return (TRUE);
}
