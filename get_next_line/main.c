/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:56:47 by qdiaz             #+#    #+#             */
/*   Updated: 2016/01/14 11:43:01 by qdiaz            ###   ########.fr       */
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
	//ret = 1;
	if (argc == 2)
	{
		//while (ret == 1)
		//{
			ret = get_next_line(fd, &str);
			if (ret == 1)
			{
				ft_putnbr(ret);
				ft_putstr(" --> ");
				ft_putstr(str);
				//if (str)
				//	free(str);
			}
			if (ret == -1)
				ft_putendl("An error occured");
			if (ret == 0 || ret == -1)
				return (0);
			//while (1) {}
		//}
	}
	ft_putchar('\n');
	return (0);
}
