/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:07:57 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/21 14:16:46 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*ptr && ((*ptr >= '\t' && *ptr <= '\r') || *ptr == ' '))
		ptr++;
	if (*ptr && (*ptr == '+' || *ptr == '-'))
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr && (*ptr >= '0' && *ptr <= '9'))
	{
		res = res * 10 + (*ptr - '0');
		ptr++;
	}
	return (res * sign);
}
