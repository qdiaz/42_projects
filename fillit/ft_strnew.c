/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:02:31 by adu-pelo          #+#    #+#             */
/*   Updated: 2015/12/15 13:32:47 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (s)
	{
		ft_bzero(s, size + 1);
		return (s);
	}
	return (NULL);
}
