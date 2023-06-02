/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:44:57 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/20 21:16:17 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*current;

	if (!*lst)
		return ;
	prev = *lst;
	current = prev;
	while (current->next)
	{
		current = current->next;
		del(prev->content);
		free(prev);
		prev = current;
	}
	del(current->content);
	free(current);
	*lst = NULL;
}
