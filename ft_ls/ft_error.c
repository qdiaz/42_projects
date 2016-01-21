/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:24:48 by qdiaz             #+#    #+#             */
/*   Updated: 2016/01/19 15:28:49 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_arg(char arg)
{
	ft_putstr_fd("ft_ls : illegal option --", 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("\nusage: ft_ls [-Rafglrtu1] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

void	basicerror(char *name, char *error, int ex)
{
	ft_putstr_fd(name, 2);
	perror(error);
	if (ex)
		exit(EXIT_FAILURE);
}
