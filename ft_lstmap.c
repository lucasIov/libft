/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovine <lucas.iovine@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:57:12 by liovine           #+#    #+#             */
/*   Updated: 2026/11/04 12:13:37 by liovine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \param lst address of a pointer to a node
 * \param f   address of the function applied to each node's content
 * \param del address of the function used to delete a node's content if needed
 *
 * \return The new list or NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_first;
	t_list	*new_elem;
	t_list	*prev;

	if (!lst || !f || !del)
		return (NULL);
	new_first = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_first, del);
			ft_lstdelone(lst, del);
			return (NULL);
		}
		if (!new_first)
			new_first = new_elem;
		else
			prev->next = new_elem;
		prev = new_elem;
		lst = lst->next;
	}
	return (new_first);
}
