/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:49:11 by qdiaz             #+#    #+#             */
/*   Updated: 2017/09/21 18:53:12 by qdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hexa(unsigned long addr)
{
	const char	*hex;

	hex = "0123456789abcdef";
	if (addr >= 16)
	{
		ft_print_hexa(addr / 16);
		ft_print_hexa(addr % 16);
	}
	else
		ft_putchar(hex[addr]);
}

void	ft_print_memory(void *mem)
{
	ft_putstr("0x");
	ft_print_hexa((unsigned long)mem);
}
