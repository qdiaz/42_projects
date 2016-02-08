/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:16:59 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/02 14:09:20 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	sort(char **str, int size)
{
	char	*tmp;
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp((const char *)str[i], (const char *)str[i + 1]) > 0)
		{
			tmp = str[i + 1];
			str[i + 1] = str[i];
			str[i] = tmp;
			i = 0;
		}
		i++;
	}
}

int		main()
{
	char	**str;
	int i;

	str[0] = "bonjour";
	str[1] = ".Salut";
	str[2] = "HELLO";
	str[3] = ".salut";
	str[4] = "hello";
	str[5] = "BONJOUR";
	i = 0;
	sort(str, 6);
	while (i < 6)
	{
		ft_putstr(str[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
