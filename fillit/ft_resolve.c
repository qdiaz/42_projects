/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:04:30 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/01/12 15:46:40 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_resol(int ***tab, int nb_tetri)
{
	int		**resol;
	int		size_resol;
	int		sol;

	size_resol = ft_define_min_sqr(nb_tetri * 4);
	sol = 0;
	while (sol == FALSE)
	{
		if (!(resol = ft_create_map(size_resol)))
			ft_error();
		sol = ft_recursive_resol(tab, resol, 0);
		size_resol++;
	}
	return (resol);
}
