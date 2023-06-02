/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:18 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/25 19:51:04 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlchar(char c, t_ind *lst)
{
	write(1, &c, 1);
	lst->len++;
}

void	ft_putlstr(char *str, t_ind *lst)
{
	if (!str)
	{
		ft_putlstr("(null)", lst);
		return ;
	}
	while (*str)
	{
		ft_putlchar(*str, lst);
		str++;
	}
}
