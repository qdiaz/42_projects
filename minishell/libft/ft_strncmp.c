/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:23:20 by qdiaz             #+#    #+#             */
/*   Updated: 2015/11/30 14:40:27 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *tmps1;
	unsigned char *tmps2;

	tmps1 = (unsigned char *)s1;
	tmps2 = (unsigned char *)s2;
	while (*tmps1 != '\0' && *tmps1 == *tmps2 && n > 0)
	{
		tmps1++;
		tmps2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*tmps1 - *tmps2);
}
