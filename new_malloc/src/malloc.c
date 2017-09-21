/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:46:26 by qdiaz             #+#    #+#             */
/*   Updated: 2017/09/21 17:14:10 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void	*tiny(size_t size)
{
	t_block *block;

	if ((block = check_size(g_zone.tiny, size)))
		add_block(&block, size);
	else if ((block = check_free_block(&(g_zone.tiny),
					size + sizeof(t_block))))
		split_block(&block, size);
	else if ((block = new_tiny_block(size)) == NULL)
		return (NULL);
	return (block->mem);
}

void	*small(size_t size)
{
	t_block *block;

	if ((block = check_size(g_zone.small, size)))
		add_block(&block, size);
	else if ((block = check_free_block(&(g_zone.small),
					size + sizeof(t_block))))
		split_block(&block, size);
	else if ((block = new_small_block(size)) == NULL)
		return (NULL);
	return (block->mem);
}

void	*large(size_t size)
{
	t_block *block;

	if ((block = last_node(&(g_zone.large))))
	{
		if ((block->next = (t_block *)mmap(0, size, PROT, MAP, -1, 0))
				== MAP_FAILED)
			return (NULL);
		block = block->next;
	}
	else
	{
		if ((g_zone.large = (t_block *)mmap(0, size, PROT, MAP, -1, 0))
				== MAP_FAILED)
			return (NULL);
		block = g_zone.large;
	}
	block->size = size - sizeof(t_block);
	block->free = 0;
	block->mem = block + 1;
	return (block->mem);
}

void	*hub(size_t size)
{
	void *mem;

	if (size <= 0)
		return (NULL);
	if (size <= TINY_SIZE)
		mem = tiny(size);
	else if (size <= SMALL_SIZE)
		mem = small(size);
	else
		mem = large(size + sizeof(t_block));
	if (!mem)
		return (NULL);
	return (mem);
}

void	*malloc(size_t size)
{
	void *mem;

	pthread_mutex_lock(&g_mutex);
	mem = hub(size);
	pthread_mutex_unlock(&g_mutex);
	return (mem);
}
