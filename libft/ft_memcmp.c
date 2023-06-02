/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:02:00 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/14 14:04:01 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t num)
{
	size_t	i;
	int		cmp;
	char	*p1;
	char	*p2;

	i = 0;
	cmp = 0;
	p1 = (char *)s1;
	p2 = (char *)s2;
	while (i < num && cmp == 0)
	{
		cmp = (unsigned char)p1[i] - (unsigned char)p2[i];
		i++;
	}
	return (cmp);
}
