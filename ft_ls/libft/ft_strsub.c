/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:03:34 by adu-pelo          #+#    #+#             */
/*   Updated: 2015/12/09 15:17:54 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	str = (char *)malloc((len + 1) * sizeof(*s));
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, &(s[start]), len);
	str[len] = '\0';
	return (str);
}
