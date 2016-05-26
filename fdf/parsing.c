/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:06:22 by qdiaz             #+#    #+#             */
/*   Updated: 2016/05/26 14:09:58 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_line(char *file)
{
	int		fd;
	char	buff;
	int		nb;

	nb = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("bad fd", 2);;
		exit(0);
	}
	while (read(fd, &buff, 1))
	{
		if (buff == '\n')
			nb++;
	}
	close(fd);
	return (nb);
}

char	**get_buff(char *file, int nb_line)
{
	int		fd;
	char	**buff;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	buff = (char **)ft_memalloc(sizeof(char *) * (nb_line + 1));
	while (get_next_line(fd, &line) > 0)
	{
		buff[i] = (char *)ft_memalloc(sizeof(char) * (ft_strlen(line) + 2));
		if (ft_strcmp(line, "") == 0)
			buff[i] = ft_strdup("-2000000000");
		else
			buff[i] = ft_strcpy(buff[i], line);
		i++;
		free(line);
	}
	close(fd);
	return (buff);
}

int		**buff_to_map(char **buff, int nb_line)
{
	int		**map;
	int		i;
	int		n;
	char	**split;

	i = -1;
	n = -1;
	map = (int **)ft_memalloc(sizeof(int *) * (nb_line + 1));
	while (buff[++i])
	{
		split = ft_strsplit(buff[i], ' ');
		map[i] = (int *)ft_memalloc(sizeof(int) * (ft_strlen(buff[i] + 1)));
		while (split[++n])
		{
			map[i][n] = ft_atoi(split[n]);
			free(split[n]);
		}
		map[i][n] = -2000000000;
		n = -1;
		free(buff[i]);
		free(split);
	}
	return (map);
}

int		**get_map(char *file)
{
	char	**buff;
	int		nb_line;
	int		**map;

	nb_line = count_line(file);
	buff = get_buff(file, nb_line);
	map = buff_to_map(buff, nb_line);
	free(buff);
	return (map);
}
