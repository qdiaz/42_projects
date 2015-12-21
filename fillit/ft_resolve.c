/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:04:30 by adu-pelo          #+#    #+#             */
/*   Updated: 2015/12/17 16:51:21 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**resol(int ***tab, int nb_tetri)
{
	int		**resol;
	int		size_resol;
	int		sol;

	size_resol = ft_define_min_sqr(nb_tetri);
	sol = 0;
	while (sol == 0)
	{
		if ((resol = ft_create_map(size_resol)) == NULL)
			return (NULL);
		sol = recursive_placement(tab, resol, 0);
		size_resol++;
	}
	return (resol);
}
