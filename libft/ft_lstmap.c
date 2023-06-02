/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:29:34 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/20 21:43:38 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*add;
	t_list	*first;

	if (!lst)
		return (NULL);
	current = lst;
	add = ft_lstnew(f(current->content));
	if (!add)
		return (NULL);
	first = add;
	while (current->next)
	{
		current = current->next;
		add->next = ft_lstnew(f(current->content));
		if (!add->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		add = add->next;
	}
	return (first);
}
