/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:46:56 by qdiaz             #+#    #+#             */
/*   Updated: 2017/09/21 18:12:11 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_block		*new_tiny_block(size_t size)
{
	t_block	*block;

	if ((block = last_node(&(g_zone.tiny))))
	{
		if ((block->next = (t_block *)mmap(0, TINY_ZONE, PROT, MAP, -1, 0))
				== MAP_FAILED)
			return (NULL);
		block = block->next;
	}
	else
	{
		if ((g_zone.tiny = (t_block *)mmap(0, TINY_ZONE, PROT, MAP, -1, 0))
				== MAP_FAILED)
			return (NULL);
		block = g_zone.tiny;
	}
	block->size = TINY_ZONE - sizeof(t_block);
	split_block(&block, size);
	return (block);
}

t_block		*new_small_block(size_t size)
{
	t_block	*block;

	if ((block = last_node(&(g_zone.small))))
	{
		if ((block->next = (t_block *)mmap(0, SMALL_ZONE, PROT, MAP, -1, 0))
				== MAP_FAILED)
			return (NULL);
		block = block->next;
	}
	else
	{
		if ((g_zone.small = (t_block *)mmap(0, SMALL_ZONE, PROT, MAP, -1, 0))
				== MAP_FAILED)
			return (NULL);
		block = g_zone.small;
	}
	block->size = SMALL_ZONE - sizeof(t_block);
	split_block(&block, size);
	return (block);
}
