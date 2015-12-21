/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:05:03 by adu-pelo          #+#    #+#             */
/*   Updated: 2015/12/18 16:32:53 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         ft_count_tetri(char *str)
{
	int i;
	int cnt;

	i = 0;
	cnt = 1;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			cnt++;
		i++;
	}
	ft_putstr("\n\nnb tetri : "); // test
	ft_putnbr(cnt); // test
	ft_putchar('\n');
	return (cnt);
}

static int	ft_check_next_diez(int ***tetri, int i, int l, int c)
{
	if (tetri[i][l][c] != 0) 
	{
		if (tetri[i][l][c + 1] != 0)
		{
			ft_putstr("voisin a droite\n");
			return (TRUE);
		}
		else if (tetri[i][l + 1][c] != 0)
		{
			ft_putstr("voisin dessous\n");
			return (TRUE);
		}
		else if (tetri[i][l][c - 1] != 0)
		{
			ft_putstr("voisin a gauche\n");
			return (TRUE);
		}
	}
	return (FALSE);
}

int			ft_check_shape(int ***tetri, int nb_tetri, int l, int c)
{
	int i;
	int diez;

	i = 0;
	while (i < nb_tetri)
	{
		l = 0;
		diez = 0;
		while (l < 4)
		{
			c = 0;
			while (c < 4)
			{
				if (tetri[i][l][c] != 0 && diez != 3)
				{
					if (ft_check_next_diez(tetri, i, l, c) == FALSE)
						return (FALSE);
					diez++;
				}
				else if (tetri[i][l][c] != 0 && diez == 3)
					diez++;
				c++;
			}
			l++;
		}
		if (diez != 4)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
