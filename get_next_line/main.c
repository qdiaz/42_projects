/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 14:52:16 by qdiaz             #+#    #+#             */
/*   Updated: 2016/01/23 14:52:20 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		ret_value;
	char	*line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	ret_value = 1;
	while (ret_value == 1)
	{
		ret_value = get_next_line(fd, &line);
		printf("%d || %s\n", ret_value, line);
	}
	close(fd);
	return (0);
}
