/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:27:18 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/11 18:24:16 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t num)
{
	size_t	i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (i < num)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
