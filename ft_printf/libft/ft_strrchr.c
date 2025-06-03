/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:34:40 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/06 15:24:30 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*p;
	unsigned char	ch;

	ch = (unsigned char)c;
	p = NULL;
	while (*s)
	{
		if (*s == ch)
			p = (char *)s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	else if (*s == '\0' && p != NULL)
		return (p);
	else
		return (p);
}
