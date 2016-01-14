/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:57:13 by qdiaz             #+#    #+#             */
/*   Updated: 2016/01/13 16:44:23 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_realloc(int const fd, char **tmp, int *ret)
{
	char	buffer[BUFF_SIZE + 1];
	char	*to_free;

	ft_memset(buffer, 0, BUFF_SIZE + 1);
	if ((*ret = read(fd, buffer, BUFF_SIZE)) == -1)
		return (-1);
	if (*tmp == '\0')
		*tmp = ft_strnew(0);
	buffer[*ret] = '\0';
	to_free = *tmp;
	*tmp = ft_strjoin(*tmp, buffer);
	//if (to_free)
		free(to_free);
	return (0);
}

static int		ft_get_nl(char **tmp, char **line)
{
	char	*str;

	if ((str = ft_strchr(*tmp, '\n')))
	{
		*str = '\0';
		*line = ft_strdup(*tmp);
		ft_memmove(*tmp, str + 1, ft_strlen(str + 1) + 1);
		//if (*line)
			free(*line);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*tmp[1024];
	int				ret;

	if (!line || fd < 0)
		return (-1);
	ret = BUFF_SIZE;
	while (ret > 0 || ft_strlen(tmp[fd]))
	{
		if ((ft_get_nl(&tmp[fd], line)) == 1)
			return (1);
		if (ft_realloc(fd, &tmp[fd], &ret) == -1)
			return (-1);
		if (ret == 0 && ft_strlen(tmp[fd]))
		{
			*line = ft_strdup(tmp[fd]);
			ft_bzero(tmp[fd], ft_strlen(tmp[fd]));
			return (1);
		}
	}
	free(tmp[fd]);
	*tmp = NULL;
	return (0);
}
