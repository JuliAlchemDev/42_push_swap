/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 21:22:43 by aserio            #+#    #+#             */
/*   Updated: 2026/05/19 23:21:41 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * Iterates through the list ’lst’, applies the function ’f’ to each node’s
 * content, and creates a new list resulting of the successive applications of
 * the function ’f’.
 * The ’del’ function is used to delete the content of a node if needed.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	if (lst->next)
	{
		new_lst->next = ft_lstmap(lst->next, f, del);
		if (!(new_lst->next))
		{
			ft_lstdelone(new_lst, del);
			return (NULL);
		}
	}
	return (new_lst);
}
