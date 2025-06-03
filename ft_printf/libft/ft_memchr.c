/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:02:06 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/02 17:55:40 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	size_t				i;

	s1 = (const unsigned char *)s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (s1[i] == (unsigned char) c)
			return ((void *)&s1[i]);
		i++;
	}
	return (NULL);
}
