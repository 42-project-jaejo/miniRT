/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:15:10 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/15 21:03:13 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*tt_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (*lst == NULL || del == NULL)
		return (NULL);
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*save;
	void	*new_content;

	if (f == NULL || del == NULL)
		return (NULL);
	new = NULL;
	while (lst)
	{
		new_content = f(lst -> content);
		if (new_content == NULL)
			return (tt_lstclear(&new, del));
		save = ft_lstnew(new_content);
		if (save == NULL)
		{
			del(new_content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, save);
		lst = lst -> next;
	}
	return (new);
}
