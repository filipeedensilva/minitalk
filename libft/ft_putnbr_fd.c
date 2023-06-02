/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:07:21 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/19 19:17:32 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= INT_MIN && n <= INT_MAX)
	{
		if (n == INT_MIN)
		{
			ft_putstr_fd("-2", fd);
			ft_putnbr_fd(147483648, fd);
		}
		else if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
		else if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}			
		else
		{
			n = n + '0';
			ft_putchar_fd(n, fd);
		}	
	}
}
