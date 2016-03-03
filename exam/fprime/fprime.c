/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:03:02 by qdiaz             #+#    #+#             */
/*   Updated: 2016/03/02 14:11:18 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		fprime(int nb)
{
	int		n;

	if (nb == 0)
	{
		printf("0");
		return (0);
	}
	if (nb == 1)
	{
		printf("1");
		return (0);
	}
	while (1)
	{
		n = 1;
		while (++n <= nb)
		{
			if (nb % n == 0)
			{
				printf("%d", n);
				nb = nb / n;
				break;
			}
		}
		if (nb == 1)
			break;
		else
			printf("*");
	}
	return (0);
}

int		main(int ac, char **av)
{
	int ret;

	if (ac == 2)
	{
		if (!(av[1][0]))
		{
			printf("\n");
			return (0);
		}
		ret = fprime(atoi(av[1]));
	}
	printf("\n");
	return (0);
}
