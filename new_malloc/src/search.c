/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:46:41 by qdiaz             #+#    #+#             */
/*   Updated: 2017/09/21 18:47:26 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_block		*search_node(t_block *block, void *mem)
{
	while (block)
	{
		if (block->mem == mem)
			return (block);
		block = block->next;
	}
	return (NULL);
}

t_block		*search_mem(void *mem)
{
	t_block	*block;

	if ((block = search_node(g_zone.tiny, mem)))
		return (block);
	else if ((block = search_node(g_zone.small, mem)))
		return (block);
	else if ((block = search_node(g_zone.large, mem)))
		return (block);
	return (NULL);
}
