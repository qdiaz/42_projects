/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 14:51:26 by qdiaz             #+#    #+#             */
/*   Updated: 2016/01/23 14:51:30 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_mem_concat(char *str, char *buf)
{
	char *tmp;

	tmp = ft_strjoin(str, buf);
	ft_strdel(&str);
	return (tmp);
}

static int		ft_get_line(char **line, char *buf, char *overf)
{
	char *tmp;

	if ((tmp = ft_strchr(buf, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(buf);
		ft_memmove(overf, tmp + 1, ft_strlen(tmp + 1) + 1);
		return (1);
	}
	else if ((tmp = ft_strchr(buf, '\0')))
	{
		*line = ft_strdup(buf);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char overf[255][BUFF_SIZE + 1];
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	if (ft_get_line(line, overf[fd], overf[fd]) == 1)
		return (1);
	str = ft_strdup(overf[fd]);
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		str = ft_mem_concat(str, buf);
		if (ft_get_line(line, str, overf[fd]) == 1)
		{
			ft_strdel(&str);
			return (1);
		}
	}
	return (ft_strlen(*line) != 0);
}
