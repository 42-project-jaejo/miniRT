/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:23:46 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/06 15:24:51 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
