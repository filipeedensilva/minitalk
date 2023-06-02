/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:09:37 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/14 22:23:04 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l_s1;
	size_t	l_s2;
	size_t	i;
	char	*str;

	i = 0;
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (l_s1 + l_s2) + 1);
	if (!str)
		return (NULL);
	while (i < l_s1)
		str[i++] = *s1++;
	while (i < l_s1 + l_s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
