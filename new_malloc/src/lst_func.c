/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:46:20 by qdiaz             #+#    #+#             */
/*   Updated: 2017/09/21 18:54:56 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_block		*last_node(t_block **head)
{
	t_block *tmp;

	tmp = *head;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_block		*check_free_block(t_block **head, size_t size)
{
	t_block *tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->free && tmp->size >= size)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_block		*check_size(t_block **head, size_t size)
{
	t_block *tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->free && tmp->size == size)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		add_block(t_block **block, size_t size)
{
	t_block *tmp;

	tmp = *block;
	tmp->size = size;
	tmp->free = 0;
	tmp->mem = tmp + 1;
}

void		split_block(t_block **block, size_t size)
{
	t_block *new_block;
	t_block *trash_block;
	t_block *next_block;

	new_block = *block;
	if (new_block->next)
		next_block = new_block->next;
	else
		next_block = NULL;
	new_block->free = 0;
	new_block->mem = new_block + 1;
	new_block->next = (void *)new_block->mem + size;
	trash_block = new_block->next;
	trash_block->size = new_block->size - size - sizeof(t_block);
	trash_block->free = 1;
	trash_block->mem = trash_block + 1;
	new_block->size = size;
	trash_block->next = next_block;
}
