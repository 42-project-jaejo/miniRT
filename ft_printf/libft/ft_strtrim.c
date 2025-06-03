/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 21:23:37 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/15 21:04:59 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char s1, const char *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*temp;

	start = 0;
	i = 0;
	end = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && check(s1[start], set))
		start++;
	while (end > start && check(s1[end - 1], set))
		end--;
	temp = (char *)malloc (sizeof(char) * (end - start + 1));
	if (temp == 0)
		return (NULL);
	while (start < end)
		temp[i++] = s1[start++];
	temp[i] = '\0';
	return (temp);
}
