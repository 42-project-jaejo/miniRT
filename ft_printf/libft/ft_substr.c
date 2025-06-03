/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:55:15 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/06 18:00:45 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;

	if (start >= ft_strlen(s) || s == NULL)
	{
		temp = (char *)malloc (sizeof(char) * 1);
		if (temp == NULL)
			return (NULL);
		temp[0] = '\0';
		return (temp);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	temp = (char *)malloc (sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[len] = '\0';
	return (temp);
}
