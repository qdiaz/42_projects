/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_ws.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:14:31 by qdiaz             #+#    #+#             */
/*   Updated: 2016/05/24 15:22:31 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_array_size(char const *s)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (*s)
	{
		if (i == 1 && ft_isspace(*s))
			i = 0;
		if (i == 0 && !ft_isspace(*s))
		{
			i = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int		ft_word_len(char const *s)
{
	int		len;

	len = 0;
	while (*s && !ft_isspace(*s))
	{
		s++;
		len++;
	}
	return (len);
}

char			**ft_strsplit_ws(char const *s)
{
	int		i;
	int		nb_word;
	char	**tab;

	i = 0;
	nb_word = ft_array_size(s);
	tab = (char **)malloc(sizeof(char *) * ((ft_array_size(s)) + 1));
	if (tab == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s && ft_isspace(*s))
			s++;
		tab[i] = ft_strsub((const char *)s, 0, ft_word_len(s));
		if (tab[i] == NULL)
			return (NULL);
		s = s + ft_word_len(s);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
