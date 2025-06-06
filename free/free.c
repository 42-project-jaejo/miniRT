/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:40:56 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/04 22:44:35 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./free.h"

void	split_free(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		data[i++] = NULL;
	}
	free(data);
}

void	list_free(t_object *list)
{
	t_object	*temp;

	while (list)
	{
		temp = list->next;
		free(list->element);
		free(list);
		list = temp;
	}
}
