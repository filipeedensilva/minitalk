/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:30:45 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/20 16:33:26 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int num)
{
	int		i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		i++;
	}
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static void	chr_cpy(long num, int i, char *str)
{
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[i--] = (num % 10) + '0';
		num = num / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		i;

	num = n;
	i = count(num);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (num)
	{
		chr_cpy(num, i, str);
		return (str);
	}
	else
		str[i] = '0';
	return (str);
}
