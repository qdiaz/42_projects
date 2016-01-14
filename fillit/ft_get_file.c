/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:05:38 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/01/07 16:06:04 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_file(char *file)
{
	int		fd;
	char	*buffer;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	buffer = ft_strnew(BUFF_SIZE);
	ft_bzero(buffer, BUFF_SIZE);
	if (read(fd, buffer, BUFF_SIZE) == -1)
		ft_error();
	if (close(fd) == -1)
		ft_error();
	return (buffer);
}
