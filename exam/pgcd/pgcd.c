/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 15:25:18 by qdiaz             #+#    #+#             */
/*   Updated: 2016/02/17 15:48:33 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		pgcd(int a, int b)
{
	if (b > a)
		return (pgcd (b, a));
	if (b == 0)
		return (a);
	return (pgcd (b, a - b));
}


int		main(int ac, char **av)
{
	int a;
	int b;
	int res;

	a = atoi((const char *)av[1]);
	b = atoi((const char *)av[2]);
	if (ac == 3 && a > 0 && b > 0)
	{
		res = pgcd(a, b);
		printf("%d", res);
	}
	printf("\n");
	return (0);
}
