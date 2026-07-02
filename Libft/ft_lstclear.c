/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserio <aserio@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:45:35 by aserio            #+#    #+#             */
/*   Updated: 2026/05/19 23:23:22 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * Deletes and frees the given node and all its successors, using the function
 * ’del’ and free(3).
 * Finally, set the pointer to the list to NULL.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (!*lst)
	{
		return ;
	}
	if ((*lst)->next)
		ft_lstclear(&((*lst)->next), del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
