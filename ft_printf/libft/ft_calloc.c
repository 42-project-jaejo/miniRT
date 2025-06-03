/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:08:09 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/04 00:26:23 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*i;
	size_t	mem;
	size_t	max;

	max = (size_t)(-1);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	mem = size * nmemb;
	if (max / nmemb < size)
		return (NULL);
	i = malloc(mem);
	if (i == NULL)
		return (NULL);
	return (ft_memset(i, 0, size * nmemb));
}
