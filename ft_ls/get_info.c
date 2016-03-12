/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:46:39 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/12 15:22:38 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst	*get_info(t_lst *head, char *file, char *path)
{
	struct stat		st;
	t_lst			*new;
	t_lst			*ptr;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	ptr = head;
	if (lstat(path, &st) <= 0)
		fill_info(st, new, file, path);
	if (head == NULL)
		return (new);
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	return (head);
}
