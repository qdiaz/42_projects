/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:33:39 by qdiaz             #+#    #+#             */
/*   Updated: 2017/09/25 15:36:22 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <pthread.h>
# include <libft.h>

# define TINY_SIZE		(size_t)getpagesize() * 2
# define SMALL_SIZE		(size_t)getpagesize() * 16
# define TINY_ZONE		(size_t)(TINY_SIZE + sizeof(t_block)) * 100
# define SMALL_ZONE		(size_t)(SMALL_SIZE + sizeof(t_block)) * 100

# define PROT			PROT_READ | PROT_WRITE
# define MAP			MAP_ANON | MAP_PRIVATE

typedef struct		s_block
{
	size_t			size;
	int				free;
	void			*mem;
	struct s_block	*next;
}					t_block;

typedef struct		s_zone
{
	struct s_block	*tiny;
	struct s_block	*small;
	struct s_block	*large;
}					t_zone;

t_zone				g_zone;
pthread_mutex_t		g_mutex;

void				*tiny(size_t size);
void				*small(size_t size);
void				*large(size_t size);
void				*hub(size_t size);
void				*malloc(size_t size);

void				free_large(t_block *block, t_block *header);
void				free(void *ptr);

void				*join_block(t_block *block, size_t size);
void				*realloc_hub(t_block *block, size_t size);
void				*realloc(void *ptr, size_t size);

t_block				*search_node(t_block *block, void *mem);
t_block				*search_mem(void *ptr);

void				split_block(t_block **block, size_t size);
void				add_block(t_block **block, size_t size);
t_block				*check_free_block(t_block **head, size_t size);
t_block				*check_size(t_block **head, size_t size);
t_block				*new_tiny_block(size_t size);
t_block				*new_small_block(size_t size);
t_block				*last_node(t_block **head);

size_t				print_alloc_mem(t_block *block, char *typ_mem);
void				show_alloc_mem(void);

#endif
