/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:28:43 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/17 02:29:21 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

void	object_add(t_object **list, t_object *new)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

t_object	*object_last(t_object *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
