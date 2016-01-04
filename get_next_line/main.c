/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:56:47 by qdiaz             #+#    #+#             */
/*   Updated: 2016/01/04 14:32:37 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		ret;

	if (argc == 2)
		fd = open(argv[1], O_RDWR | O_CREAT);
	else
		fd = 0;
	while (1)
	{
		ret = get_next_line(fd, &str);
		ft_putnbr(ret);
		ft_putendl(str);
		if (ret == -1)
			ft_putendl("An error occured");
		if (ret == 0 || ret == -1)
			return (0);
	}
	return (0);
}
