/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:40:23 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/26 19:13:30 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlnbr(long num, t_ind *lst)
{
	if (num < 0)
	{
		ft_putlchar('-', lst);
		ft_putlnbr(-num, lst);
	}
	else if (num > 9)
	{
		ft_putlnbr(num / 10, lst);
		ft_putlnbr(num % 10, lst);
	}
	else
	{
		num = num + '0';
		ft_putlchar(num, lst);
	}
}

void	ft_putlptr(size_t ptr, t_ind *lst)
{
	if (!ptr)
		ft_putlstr("(nil)", lst);
	else
	{
		if (ptr < 16)
		{
			ft_putlstr("0x", lst);
			ft_putlchar(HEX_LOWER[ptr % 16], lst);
			return ;
		}
		ft_putlptr(ptr / 16, lst);
		ft_putlchar(HEX_LOWER[ptr % 16], lst);
	}
}

void	ft_converter(unsigned int x, char *base, t_ind *lst)
{
	if (x / 16 == 0)
	{
		ft_putlchar(base[x % 16], lst);
		return ;
	}
	else
	{
		ft_converter(x / 16, base, lst);
		ft_putlchar(base[x % 16], lst);
	}
}

void	ft_putlhex(unsigned int x, char c, t_ind *lst)
{
	if (c == 'x')
		ft_converter(x, HEX_LOWER, lst);
	else if (c == 'X')
		ft_converter(x, HEX_UPPER, lst);
}
