/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:05:43 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/24 17:29:43 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				tmp = 0;
				i = 0;
			}
			else
				i++;
		}
	}
}

int		main()
{
	int				tab[6];
	unsigned int	size;
	int				i;

	tab[0] = 6;
	tab[1] = 3;
	tab[2] = 1;
	tab[3] = 2;
	tab[4] = 5;
	tab[5] = 2;
	size = 6;
	i = 0;
	sort_int_tab(tab, size);
	while (i < size)
	{
		printf("| %d |", tab[i]);
		i++;
	}
	return (0);
}
