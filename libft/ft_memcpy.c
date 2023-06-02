/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:14:23 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/14 18:15:38 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t num)
{
	size_t	i;
	char	*dest;
	char	*src;

	if (!s && !d)
		return (NULL);
	i = 0;
	dest = (char *) d;
	src = (char *) s;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
