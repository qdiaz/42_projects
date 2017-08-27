/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:10:59 by qdiaz             #+#    #+#             */
/*   Updated: 2017/08/27 20:48:57 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int		main(int argc, char **argv)
{
	int page_size;

	argc = 0;
	argv[0] = "coucou";
	page_size = getpagesize();
	printf("page_size = %d\n", page_size);
	return (0);
}
